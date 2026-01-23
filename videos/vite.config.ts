import { defineConfig } from 'vite';
import motionCanvas from '@motion-canvas/vite-plugin';
import ffmpeg from '@motion-canvas/ffmpeg';
import path from 'path'

export default defineConfig({
    resolve: {
        alias: {
            '@': path.resolve(__dirname, './src'),
            '@assets': path.resolve(__dirname, './assets'),
        }
    },
    plugins: [
        motionCanvas({
            project: ['./src/assignment*.ts']
        }),
        ffmpeg(),
    ],
});
