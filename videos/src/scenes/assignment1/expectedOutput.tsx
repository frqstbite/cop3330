import { Code, insert, makeScene2D, remove, replace } from "@motion-canvas/2d";
import {
    BBox,
    createRef,
    createSignal,
    waitUntil,
    zoomOutTransition,
} from "@motion-canvas/core";

export default makeScene2D(function* (view) {
    // Main visuals
    const code = createRef<Code>();
    const linesize = createSignal(48);

    view.add(
        <Code
            ref={code}
            fontSize={48}
            code={`\
int main() {

}`}
        />,
    );

    // Transition in
    const viewSize = view.size();
    yield* zoomOutTransition(
        new BBox(
            viewSize.x / 4,
            viewSize.y / 4,
            viewSize.x / 2,
            viewSize.y / 2,
        ),
    );

    yield* waitUntil(
        "hallo",
        code().code.edit(0.6)`\
function example() {
${insert(`    // This is a comment
`)}    console.log('${replace("Hello!", "Goodbye!")}');
${remove(`    return 7;
`)}}`,
    );

    yield* code().code.edit(0.6)`\
function example() {
  ${insert(`// This is a comment
  `)}console.log('${replace("Hello!", "Goodbye!")}');
${remove(`  return 7;
`)}}`;

    yield* code().code.append("\nconst two = 2;", 0.6);
});
