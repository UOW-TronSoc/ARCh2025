import React from 'react';
import HelloWorld from './pages/HelloWorld';
import { Route, Routes } from 'react-router-dom';


function App() {
  return (
    <div>
      <Routes>
        <Route path='/HelloWorld' element = {
            <HelloWorld />
          }
        />
        {/* <Route path='/' element={< />} /> */}
        </Routes>
    </div>
  );
}

export default App;