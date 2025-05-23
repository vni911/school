import { db } from '@common/firebase/config';
import { collection, addDoc } from 'firebase/firestore';
import { useScheduleStore } from '@common/store/scheduleStore';

function App() {
    const { selectedTimes, addTime } = useScheduleStore();

    const saveToFirestore = async () => {
        try {
            const docRef = await addDoc(collection(db, 'schedules'), {
                times: selectedTimes,
                createdAt: new Date(),
            });
            alert('저장 성공! 문서 ID: ' + docRef.id);
        } catch (e) {
            console.error('저장 실패:', e);
        }
    };

    return (
        <div>
            <h1>시간 선택</h1>
            <button onClick={() => addTime('2025-05-25T10:00')}>10시 선택</button>
            <button onClick={saveToFirestore}>Firestore에 저장</button>
            <pre>{JSON.stringify(selectedTimes, null, 2)}</pre>
        </div>
    );
}