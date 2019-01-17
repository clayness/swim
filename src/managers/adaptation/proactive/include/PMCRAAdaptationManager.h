/*******************************************************************************
 * PLA Adaptation Manager
 *
 * Copyright 2017 Carnegie Mellon University. All Rights Reserved.
 * 
 * NO WARRANTY. THIS CARNEGIE MELLON UNIVERSITY AND SOFTWARE ENGINEERING
 * INSTITUTE MATERIAL IS FURNISHED ON AN "AS-IS" BASIS. CARNEGIE MELLON
 * UNIVERSITY MAKES NO WARRANTIES OF ANY KIND, EITHER EXPRESSED OR IMPLIED, AS
 * TO ANY MATTER INCLUDING, BUT NOT LIMITED TO, WARRANTY OF FITNESS FOR PURPOSE
 * OR MERCHANTABILITY, EXCLUSIVITY, OR RESULTS OBTAINED FROM USE OF THE
 * MATERIAL. CARNEGIE MELLON UNIVERSITY DOES NOT MAKE ANY WARRANTY OF ANY KIND
 * WITH RESPECT TO FREEDOM FROM PATENT, TRADEMARK, OR COPYRIGHT INFRINGEMENT.
 *
 * Released under a BSD-style license, please see license.txt or contact
 * permission@sei.cmu.edu for full terms.
 *
 * [DISTRIBUTION STATEMENT A] This material has been approved for public release
 * and unlimited distribution. Please see Copyright notice for non-US Government
 * use and distribution.
 ******************************************************************************/

#ifndef PMCRAADAPTATIONMANAGER_H_
#define PMCRAADAPTATIONMANAGER_H_

#include <managers/adaptation/proactive/include/PMCAdaptationManager.h>

namespace pladapt {

/**
 * This class is an attempt to reproduce SDPRA with PRISM
 *
 * However it does not work because PRISM generates randomized strategies,
 * meaning that we cannot select a single tactic (or a set of tactics) to
 * be started at the current time.
 *
 * The code is left here in case PRISM later on incorporates a new solver
 * capable of generating non-randomized strategies.
 */
class PMCRAAdaptationManager: public PMCAdaptationManager {
public:
    static const char* PROBABILITY_BOUND;

    virtual ~PMCRAAdaptationManager();

    /**
 	 * params must include:
 	 *   PROBABILITY_BOUND: minimum desired probability to satisfy
 	 * @see PMCAdaptationManager::initialize()
 	 */
     void initialize(std::shared_ptr<const ConfigurationManager> configMgr, const YAML::Node& params,
     		std::shared_ptr<const PMCHelper> helper) override;
     TacticList evaluate(const Configuration& currentConfigObj, const EnvironmentDTMCPartitioned& envDTMC,
            const UtilityFunction& utilityFunction, unsigned horizon) override;

protected:
    double survivalRequirement = 1.0;
};

} /* namespace pladapt */

#endif /* PMCRAADAPTATIONMANAGER_H_ */