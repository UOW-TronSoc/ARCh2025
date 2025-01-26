import React from "react";
import Header from "../../components/Header";
import Footer from "../../components/Footer";
import KangaConnection from "../index/kanga_connection/KangaConnection";
import DeviceDetails from "../index/device_details/DeviceDetails";
import QuickOverview from "../index/quick_overview/QuickOverview";
import RoboSpec from "../index/robot_specs/RoboSpec";
import ControlCommandLogHistory from "../control_command/LogHistory";
import NLISection from "../control_command/NLISection";
import MapAndControls from "../control_command/MapAndControls";
import DataGraph from "../data_sensors/DataGraph";
import DataLogHistory from "../data_sensors/LogHistory";

const Dashboard = () => {
  return (
    <>
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
};

export default Dashboard;
