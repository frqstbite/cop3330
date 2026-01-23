import { Layout, makeScene2D, SVG, Txt } from "@motion-canvas/2d";
import {
    createRef,
    createSignal,
    fadeTransition,
    useScene,
    Vector2,
} from "@motion-canvas/core";

import logo from "@assets/motioncanvas.svg?raw";

export default makeScene2D(function* (view) {
    const scene = useScene();
    const theme = scene.variables.get("theme", null);
    const assignment = scene.variables.get("assignment", 0);

    // Refs
    const logoRef = createRef<SVG>();

    // Determine header from assignment #
    const headerSignal = createSignal();

    // Scene
    view.add(
        <Layout
            layout
            alignItems={"center"}
            direction={"column"}
            gap={25}
            height={"100%"}
            justifyContent={"center"}
        >
            <Txt
                fill={() => theme().text}
                fontFamily={() => theme().fontFamily}
                fontWeight={700}
                text={() => `Assignment ${assignment()}`}
                textAlign={"center"}
            />

            <Txt
                fill={() => theme().text}
                fontFamily={() => theme().fontFamily}
                text="COP 3360: Data Structures, Algorithms, and Generic Programming"
                textAlign={"center"}
            />

            <SVG
                ref={logoRef}
                fill={() => theme().text}
                svg={logo}
                size={[400, 400]}
            />
        </Layout>,
    );

    yield* fadeTransition(1);
    yield* logoRef().scale(2, 2).to(1, 2);
    yield* logoRef().position(new Vector2(100, 100), 2).to(Vector2.zero, 2);
});
