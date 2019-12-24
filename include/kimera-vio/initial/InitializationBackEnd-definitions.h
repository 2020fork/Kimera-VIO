/* ----------------------------------------------------------------------------
 * Copyright 2017, Massachusetts Institute of Technology,
 * Cambridge, MA 02139
 * All Rights Reserved
 * Authors: Luca Carlone, et al. (see THANKS for the full author list)
 * See LICENSE for the license information
 * -------------------------------------------------------------------------- */

/**
 * @file   InitializationBackEnd-definitions.h
 * @brief  Derived class initialization input payload.
 * @author Antoni Rosinol
 * @author Sandro Berchier
 * @author Luca Carlone
 */

#pragma once

#include <gtsam/navigation/AHRSFactor.h>

#include "kimera-vio/frontend/StereoVisionFrontEnd-definitions.h"
#include "kimera-vio/utils/Macros.h"

namespace VIO {

enum InitializationModes { GT, IMU, ALIGNMENT };

struct InitializationInputPayload : public FrontendOutput {
  KIMERA_POINTER_TYPEDEFS(InitializationInputPayload);
  KIMERA_DELETE_COPY_CONSTRUCTORS(InitializationInputPayload);
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  // Default constructor
  InitializationInputPayload(
      const bool is_keyframe,
      const StatusStereoMeasurementsPtr& status_stereo_measurements,
      const TrackingStatus& tracker_status,
      const gtsam::Pose3& relative_pose_body_stereo,
      const StereoFrame& stereo_frame_lkf,
      const ImuFrontEnd::PimPtr& pim,
      const DebugTrackerInfo& debug_tracker_info,
      const gtsam::AHRSFactor::PreintegratedMeasurements& ahrs_pim =
          gtsam::AHRSFactor::PreintegratedMeasurements())
      : FrontendOutput(is_keyframe,
                       status_stereo_measurements,
                       tracker_status,
                       relative_pose_body_stereo,
                       stereo_frame_lkf,
                       pim,
                       debug_tracker_info),
        ahrs_pim_(ahrs_pim) {}

  const gtsam::AHRSFactor::PreintegratedMeasurements ahrs_pim_;
};

}  // namespace VIO
