import React, { useState, useEffect } from "react";

const CameraFeed = () => {
  const [imageSrc, setImageSrc] = useState("");

  useEffect(() => {
    const fetchFrame = () => {
      setImageSrc(`http://localhost:8000/api/video_feed/?time=${new Date().getTime()}`);
    };

    // Refresh image every 100ms
    const interval = setInterval(fetchFrame, 100);

    return () => clearInterval(interval);
  }, []);

  return (
    <div>
      <h2>Live Camera Feed</h2>
      <img
        src={imageSrc}
        alt="Camera Feed"
        style={{ width: "100%", maxWidth: "640px", border: "2px solid black" }}
      />
    </div>
  );
};

export default CameraFeed;
