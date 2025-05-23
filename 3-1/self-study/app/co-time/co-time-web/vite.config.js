import { defineConfig } from 'vite';
import { useScheduleStore } from '../../common/store/scheduleStore';

import react from '@vitejs/plugin-react';
import path from 'path';

export default defineConfig({
  plugins: [react()],
  resolve: {
    alias: {
      '@common': path.resolve(__dirname, '../common'),
    },
  },
});
