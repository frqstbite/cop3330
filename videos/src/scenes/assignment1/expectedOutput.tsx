import { zoomTransition } from "@/common";
import { Code, insert, makeScene2D, remove, replace } from "@motion-canvas/2d";
import { createRef, createSignal, waitUntil } from "@motion-canvas/core";

export default makeScene2D(function* (view) {
    // Main visuals
    const tests = createRef<Code>();
    const linesize = createSignal(48);

    view.add(
        <Code
            ref={tests}
            fontSize={48}
            code={`\
int main() {

}`}
        />,
    );

    // Transition in
    yield* zoomTransition();

    // Test cases
    yield* waitUntil(
        "+tests",
        tests().code.edit(0.6)`\
int main() {
    ${insert(`/*
     * test cases here
     */`)}
}`,
    );

    // ???
    yield* waitUntil(
        "tests_confused",
        tests().code.edit(0.6)`\
int main() {
    /*
     * test cases here${insert("...?")}
     */
}`,
    );

    yield* waitUntil("x");
});
