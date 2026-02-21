import { makeProject } from '@motion-canvas/core';
import './common'

import intro from './scenes/intro?scene';
import expectedOutput from './scenes/assignment1/expectedOutput?scene';
import outro from './scenes/outro?scene';

import audio from '@assets/assignment1.mp3?url';
import logo from './scenes/logo?scene';

export default makeProject({
    audio,
    scenes: [intro, expectedOutput, outro, logo],
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
