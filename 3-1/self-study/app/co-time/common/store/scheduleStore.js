import { create } from 'zustand';

export const useScheduleStore = create((set) => ({
    selectedTimes: [],
    addTime: (time) =>
        set((state) => ({
            selectedTimes: [...state.selectedTimes, time],
        })),
    removeTime: (time) =>
        set((state) => ({
            selectedTimes: state.selectedTimes.filter((t) => t !== time),
        })),
    clearTimes: () => set({ selectedTimes: [] }),
}));
