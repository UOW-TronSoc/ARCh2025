import React from 'react';
import { Card, CardContent, Typography, Grid } from 'react-bootstrap';
import PropTypes from 'prop-types';
import "./QuickOverview.css";

const MetricCard = ({label, percentage}) => (
  <Card className="text-center mb-3 metric-card">
    <Card.Body>
      <p className='metric-percentage'>{percentage}%</p>
      <p className='metric-label'>{label}</p>
    </Card.Body>
  </Card>
);

MetricCard.propTypes = {
  label: PropTypes.string.isRequired,
  percentage: PropTypes.number.isRequired,
};

const QuickOverview = ({metrics}) => {
  return (
    <div className="quick-overview">
      <h3>Quick Overview</h3>
      <Row>
        {metrics.map((metric, index) => (
          <Col key={index} md={4}>
            <MetricCard label={metric.label} percentage={metric.percentage} />
          </Col>
        ))}
      </Row>
    </div>
  );
};

QuickOverview.propTypes = {
  metrics: PropTypes.arrayOf(
    PropTypes.shape({
      label: PropTypes.string.isRequired,
      percentage: PropTypes.number.isRequired,
  })).isRequired,
};

export default QuickOverview;