import React from 'react';
import ReactDOM from 'react-dom/client';
import App from './App.jsx'; // ✅ default export를 요구함
import './index.css';

ReactDOM.createRoot(document.getElementById('root')).render(
    <React.StrictMode>
        <App />
    </React.StrictMode>
);
