import { Circle, makeScene2D } from "@motion-canvas/2d";
import { createRef, Vector2 } from "@motion-canvas/core";

export default makeScene2D(function* (view) {
  // Create your animations here

  const circle = createRef<Circle>();

  view.add(<Circle ref={circle} size={320} fill={"lightseagreen"} />);

  yield* circle().position(new Vector2(100, 100), 2).to(Vector2.zero, 2);
  yield* circle().scale(2, 2).to(1, 2);
});
