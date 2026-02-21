import { Circle, Layout, makeScene2D, Rect, SVG, Txt } from "@motion-canvas/2d";
import {
    all,
    createRef,
    createSignal,
    Direction,
    easeInOutSine,
    easeOutSine,
    loopUntil,
    slideTransition,
    useScene,
    Vector2,
    waitUntil,
} from "@motion-canvas/core";

import { Logo } from "@/components/logo";

export default makeScene2D(function* (view) {
    const scene = useScene();
    const theme = scene.variables.get("theme", null);

    // Signals
    const backgroundOpacity = createSignal(0);
    const logoOpacity = createSignal(0);

    // Refs
    const logoRef = createRef<Logo>();

    view.add(
        <Rect
            layout
            opacity={backgroundOpacity}
            alignItems={"center"}
            direction={"column"}
            gap={25}
            height={"100%"}
            justifyContent={"center"}
            size={["100%", "100%"]}
            fill={() => theme().crust}
        >
            <Txt
                fill={() => theme().text}
                fontFamily="JetBrains Mono"
                fontWeight={700}
                text="Motion Canvas"
                textAlign={"center"}
            />

            <Logo
                opacity={logoOpacity}
                ref={logoRef}
                rotation={() => easeOutSine(logoOpacity(), -15, 0)}
                scale={() => easeOutSine(logoOpacity(), 3, 1)}
            />
        </Rect>,
    );

    // Transition in
    yield* slideTransition(Direction.Bottom);

    // Show Motion Canvas logo
    yield loopUntil("x", () => logoRef().animate());
    yield* all(backgroundOpacity(1, 0.5), logoOpacity(1, 1));

    // Fade out using circle
    yield* waitUntil("fade");
    const fadeAlpha = createSignal(0);
    view.add(
        <Circle
            fill={"black"}
            size={() =>
                new Vector2(
                    easeInOutSine(
                        fadeAlpha(),
                        0,
                        Vector2.magnitude(view.width() / 2, view.height() / 2),
                    ) * 2,
                )
            }
        />,
    );
    yield* fadeAlpha(1, 1);
    yield* waitUntil("x");
});
