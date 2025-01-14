import Header from './Header.jsx'
import Footer from './Footer.jsx'
import KangaConnection from './pages/index/KangaConnection.jsx';
import DeviceDetails from './pages/index/DeviceDetails.jsx';
import QuickOverview from './pages/index/QuickOverview.jsx';
import RoboSpec from './pages/index/RoboSpec.jsx';
import ControlCommandLogHistory from './pages/control_command/LogHistory.jsx';
import NLISection from './pages/control_command/NLISection.jsx';
import MapAndControls from './pages/control_command/MapAndControls.jsx';
import DataGraph from './pages/data_sensors/DataGraph.jsx'
import DataLogHistory from './pages/data_sensors/LogHistory.jsx'

function App() {
  return(
    <>
      <Header/>
        <KangaConnection />
        <div className="main-container">
          <div className="middle-section">
            <div className="left-column">
              <DeviceDetails />
              <QuickOverview />
            </div>
            <div className="right-column">
              <RoboSpec />
            </div>
          </div>
        </div>
      <Footer/>
      <KangaConnection />
      <div className="main-container">
        <div className="middle-section">
          <div className="left-column">
            <ControlCommandLogHistory />
            <NLISection />
          </div>
          <div className="right-column">
            <MapAndControls />
          </div>
        </div>
      </div>
      <KangaConnection />
      <div className="main-container">
        <div className="middle-section">
          <div className="left-column">
            <DataGraph />
          </div>
          <div className="right-column">
            <DataLogHistory />
          </div>
        </div>
      </div>
    </>
  );
}

export default App
