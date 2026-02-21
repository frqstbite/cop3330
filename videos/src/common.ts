import { Code, LezerHighlighter, useScene2D, View2D } from '@motion-canvas/2d';
import { parser } from '@lezer/cpp';
import { BBox, Color, SignalValue, useScene, useTransition, zoomOutTransition } from '@motion-canvas/core';

// Roboto
import './global.css';

// CPP formatting
Code.defaultHighlighter = new LezerHighlighter(parser);

export const EDIT_DURATION = 4;
const TRANSITION_DURATION = 1;

export function* zoomTransition() {
    const scene = useScene2D();
    const size = scene.getSize();
    yield* zoomOutTransition(
        new BBox(
            size.x / 4,
            size.y / 4,
            size.x / 2,
            size.y / 2,
        ), 1);
};