import { zoomTransition } from "@/common";
import { Layout, makeScene2D, SVG, Txt } from "@motion-canvas/2d";
import { useScene, waitUntil } from "@motion-canvas/core";

export default makeScene2D(function* (view) {
    const scene = useScene();
    const theme = scene.variables.get("theme", null);
    const assignment = scene.variables.get("assignment", 0);

    // Scene
    view.add(
        <Layout
            layout
            alignItems={"center"}
            direction={"column"}
            gap={25}
            height={"50%"}
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

            <Txt
                fill={() => theme().text}
                fontFamily={() => theme().fontFamily}
                text="Spring 2026"
                textAlign={"center"}
            />
        </Layout>,
    );

    yield* zoomTransition();
    yield* waitUntil("x");
});
