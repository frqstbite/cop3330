import { makeProject } from '@motion-canvas/core';
import './common'

import intro from './scenes/intro?scene';
import expectedOutput from './scenes/assignment1/expectedOutput?scene';
import outro from './scenes/outro?scene';

export default makeProject({
    scenes: [intro, expectedOutput, outro],
    variables: {
        assignment: 1,
        theme: {
            fontFamily: 'Roboto',

            text: '#cdd6f4',
            base: '#1e1e2e',
            mantle: '#181825',
            crust: '#11111b',
        },
    },
});
