import { makeProject } from './common'

import example from './scenes/example?scene';
import expectedOutput from './scenes/assignment1/expectedOutput?scene';

export default makeProject({
  scenes: [example, expectedOutput],
});
