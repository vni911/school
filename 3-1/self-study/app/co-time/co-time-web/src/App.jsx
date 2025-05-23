import { useScheduleStore } from '../../common/store/scheduleStore'; // 또는 @common 경로

function App() {
    const { selectedTimes, addTime } = useScheduleStore();

    return (
        <div>
            <h1>상태 테스트</h1>
            <button onClick={() => addTime('2025-05-25T10:00')}>
                10시 선택
            </button>
            <pre>{JSON.stringify(selectedTimes, null, 2)}</pre>
        </div>
    );
}

export default App; // ✅ 이 줄이 반드시 있어야 함!
