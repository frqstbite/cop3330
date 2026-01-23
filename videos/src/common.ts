import { Code, LezerHighlighter } from '@motion-canvas/2d';
import { parser } from '@lezer/cpp';
import { ProjectSettings, makeProject as makeProjectUnwrapped } from '@motion-canvas/core';

// Roboto
import './global.css';

// CPP formatting
Code.defaultHighlighter = new LezerHighlighter(parser);