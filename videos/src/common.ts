import { Code, LezerHighlighter } from '@motion-canvas/2d';
import { parser } from '@lezer/cpp';
import { ProjectSettings, makeProject as makeProjectUnwrapped } from '@motion-canvas/core';

export function makeProject(settings: ProjectSettings): ProjectSettings {
    
    // Code syntax highlighting setup
    Code.defaultHighlighter = new LezerHighlighter(parser);

    return makeProjectUnwrapped(settings);
}