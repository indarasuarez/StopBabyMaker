#include "CMS3.h"
CMS3 cms3;
namespace tas {
	TBits &hlt_bits() { return cms3.hlt_bits(); }
	vector<TString> &evt_CMS2tag() { return cms3.evt_CMS2tag(); }
	vector<TString> &evt_dataset() { return cms3.evt_dataset(); }
	vector<TString> &hlt_trigNames() { return cms3.hlt_trigNames(); }
	bool &hcalnoise_HasBadRBXTS4TS5() { return cms3.hcalnoise_HasBadRBXTS4TS5(); }
	bool &evt_cscTightHaloId() { return cms3.evt_cscTightHaloId(); }
	bool &evt_hbheFilter() { return cms3.evt_hbheFilter(); }
	bool &filt_cscBeamHalo() { return cms3.filt_cscBeamHalo(); }
	bool &filt_ecalLaser() { return cms3.filt_ecalLaser(); }
	bool &filt_ecalTP() { return cms3.filt_ecalTP(); }
	bool &filt_eeBadSc() { return cms3.filt_eeBadSc(); }
	bool &filt_goodVertices() { return cms3.filt_goodVertices(); }
	bool &filt_hbheNoise() { return cms3.filt_hbheNoise(); }
	bool &filt_hcalLaser() { return cms3.filt_hcalLaser(); }
	bool &filt_metfilter() { return cms3.filt_metfilter(); }
	bool &filt_trackingFailure() { return cms3.filt_trackingFailure(); }
	bool &filt_trkPOGFilters() { return cms3.filt_trkPOGFilters(); }
	bool &filt_trkPOG_logErrorTooManyClusters() { return cms3.filt_trkPOG_logErrorTooManyClusters(); }
	bool &filt_trkPOG_manystripclus53X() { return cms3.filt_trkPOG_manystripclus53X(); }
	bool &filt_trkPOG_toomanystripclus53X() { return cms3.filt_trkPOG_toomanystripclus53X(); }
	vector<bool> &els_conv_vtx_flag() { return cms3.els_conv_vtx_flag(); }
	vector<bool> &els_isGsfCtfScPixChargeConsistent() { return cms3.els_isGsfCtfScPixChargeConsistent(); }
	vector<bool> &els_passingMvaPreselection() { return cms3.els_passingMvaPreselection(); }
	vector<bool> &els_passingPflowPreselection() { return cms3.els_passingPflowPreselection(); }
	vector<bool> &mus_isRPCMuon() { return cms3.mus_isRPCMuon(); }
	vector<bool> &mus_tightMatch() { return cms3.mus_tightMatch(); }
	vector<bool> &mus_updatedSta() { return cms3.mus_updatedSta(); }
	vector<bool> &photons_haspixelSeed() { return cms3.photons_haspixelSeed(); }
	float &evt_bs_Xwidth() { return cms3.evt_bs_Xwidth(); }
	float &evt_bs_XwidthErr() { return cms3.evt_bs_XwidthErr(); }
	float &evt_bs_Ywidth() { return cms3.evt_bs_Ywidth(); }
	float &evt_bs_YwidthErr() { return cms3.evt_bs_YwidthErr(); }
	float &evt_bs_dxdz() { return cms3.evt_bs_dxdz(); }
	float &evt_bs_dxdzErr() { return cms3.evt_bs_dxdzErr(); }
	float &evt_bs_dydz() { return cms3.evt_bs_dydz(); }
	float &evt_bs_dydzErr() { return cms3.evt_bs_dydzErr(); }
	float &evt_bs_sigmaZ() { return cms3.evt_bs_sigmaZ(); }
	float &evt_bs_sigmaZErr() { return cms3.evt_bs_sigmaZErr(); }
	float &evt_bs_xErr() { return cms3.evt_bs_xErr(); }
	float &evt_bs_yErr() { return cms3.evt_bs_yErr(); }
	float &evt_bs_zErr() { return cms3.evt_bs_zErr(); }
	float &evt_bField() { return cms3.evt_bField(); }
	float &evt_fixgrid_all_rho() { return cms3.evt_fixgrid_all_rho(); }
	float &evt_fixgridfastjet_allcalo_rho() { return cms3.evt_fixgridfastjet_allcalo_rho(); }
	float &evt_fixgridfastjet_all_rho() { return cms3.evt_fixgridfastjet_all_rho(); }
	float &evt_fixgridfastjet_centralcalo_rho() { return cms3.evt_fixgridfastjet_centralcalo_rho(); }
	float &evt_fixgridfastjet_centralchargedpileup_rho() { return cms3.evt_fixgridfastjet_centralchargedpileup_rho(); }
	float &evt_fixgridfastjet_centralneutral_rho() { return cms3.evt_fixgridfastjet_centralneutral_rho(); }
	float &evt_kfactor() { return cms3.evt_kfactor(); }
	float &evt_scale1fb() { return cms3.evt_scale1fb(); }
	float &evt_xsec_excl() { return cms3.evt_xsec_excl(); }
	float &evt_xsec_incl() { return cms3.evt_xsec_incl(); }
	float &genps_alphaQCD() { return cms3.genps_alphaQCD(); }
	float &genps_pthat() { return cms3.genps_pthat(); }
	float &genps_qScale() { return cms3.genps_qScale(); }
	float &genps_weight() { return cms3.genps_weight(); }
	float &gen_sumEt() { return cms3.gen_sumEt(); }
	float &hcalnoise_GetRecHitEnergy() { return cms3.hcalnoise_GetRecHitEnergy(); }
	float &hcalnoise_GetRecHitEnergy15() { return cms3.hcalnoise_GetRecHitEnergy15(); }
	float &hcalnoise_GetTotalCalibCharge() { return cms3.hcalnoise_GetTotalCalibCharge(); }
	float &hcalnoise_TS4TS5NoiseSumE() { return cms3.hcalnoise_TS4TS5NoiseSumE(); }
	float &hcalnoise_TS4TS5NoiseSumEt() { return cms3.hcalnoise_TS4TS5NoiseSumEt(); }
	float &hcalnoise_eventChargeFraction() { return cms3.hcalnoise_eventChargeFraction(); }
	float &hcalnoise_eventEMEnergy() { return cms3.hcalnoise_eventEMEnergy(); }
	float &hcalnoise_eventEMFraction() { return cms3.hcalnoise_eventEMFraction(); }
	float &hcalnoise_eventHadEnergy() { return cms3.hcalnoise_eventHadEnergy(); }
	float &hcalnoise_eventTrackEnergy() { return cms3.hcalnoise_eventTrackEnergy(); }
	float &hcalnoise_flatNoiseSumE() { return cms3.hcalnoise_flatNoiseSumE(); }
	float &hcalnoise_flatNoiseSumEt() { return cms3.hcalnoise_flatNoiseSumEt(); }
	float &hcalnoise_isolatedNoiseSumE() { return cms3.hcalnoise_isolatedNoiseSumE(); }
	float &hcalnoise_isolatedNoiseSumEt() { return cms3.hcalnoise_isolatedNoiseSumEt(); }
	float &hcalnoise_max10GeVHitTime() { return cms3.hcalnoise_max10GeVHitTime(); }
	float &hcalnoise_max25GeVHitTime() { return cms3.hcalnoise_max25GeVHitTime(); }
	float &hcalnoise_maxE10TS() { return cms3.hcalnoise_maxE10TS(); }
	float &hcalnoise_maxE2Over10TS() { return cms3.hcalnoise_maxE2Over10TS(); }
	float &hcalnoise_maxE2TS() { return cms3.hcalnoise_maxE2TS(); }
	float &hcalnoise_min10GeVHitTime() { return cms3.hcalnoise_min10GeVHitTime(); }
	float &hcalnoise_min25GeVHitTime() { return cms3.hcalnoise_min25GeVHitTime(); }
	float &hcalnoise_minE10TS() { return cms3.hcalnoise_minE10TS(); }
	float &hcalnoise_minE2Over10TS() { return cms3.hcalnoise_minE2Over10TS(); }
	float &hcalnoise_minE2TS() { return cms3.hcalnoise_minE2TS(); }
	float &hcalnoise_minHPDEMF() { return cms3.hcalnoise_minHPDEMF(); }
	float &hcalnoise_minRBXEMF() { return cms3.hcalnoise_minRBXEMF(); }
	float &hcalnoise_rms10GeVHitTime() { return cms3.hcalnoise_rms10GeVHitTime(); }
	float &hcalnoise_rms25GeVHitTime() { return cms3.hcalnoise_rms25GeVHitTime(); }
	float &hcalnoise_spikeNoiseSumE() { return cms3.hcalnoise_spikeNoiseSumE(); }
	float &hcalnoise_spikeNoiseSumEt() { return cms3.hcalnoise_spikeNoiseSumEt(); }
	float &hcalnoise_triangleNoiseSumE() { return cms3.hcalnoise_triangleNoiseSumE(); }
	float &hcalnoise_triangleNoiseSumEt() { return cms3.hcalnoise_triangleNoiseSumEt(); }
	float &pdfinfo_pdf1() { return cms3.pdfinfo_pdf1(); }
	float &pdfinfo_pdf2() { return cms3.pdfinfo_pdf2(); }
	float &pdfinfo_scale() { return cms3.pdfinfo_scale(); }
	float &pdfinfo_x1() { return cms3.pdfinfo_x1(); }
	float &pdfinfo_x2() { return cms3.pdfinfo_x2(); }
	float &evt_fixgrid_rho_all() { return cms3.evt_fixgrid_rho_all(); }
	float &evt_fixgrid_rho_ctr() { return cms3.evt_fixgrid_rho_ctr(); }
	float &evt_fixgrid_rho_fwd() { return cms3.evt_fixgrid_rho_fwd(); }
	float &evt_pfmet() { return cms3.evt_pfmet(); }
	float &evt_pfmetPhi() { return cms3.evt_pfmetPhi(); }
	float &evt_pfmetSig() { return cms3.evt_pfmetSig(); }
	float &evt_pfmetSignificance() { return cms3.evt_pfmetSignificance(); }
	float &evt_pfsumet() { return cms3.evt_pfsumet(); }
	float &gen_met() { return cms3.gen_met(); }
	float &gen_metPhi() { return cms3.gen_metPhi(); }
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >  &evt_bsp4() { return cms3.evt_bsp4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_mc_motherp4() { return cms3.els_mc_motherp4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_mc_p4() { return cms3.els_mc_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_mc_motherp4() { return cms3.mus_mc_motherp4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_mc_p4() { return cms3.mus_mc_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfjets_mc_gp_p4() { return cms3.pfjets_mc_gp_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfjets_mc_motherp4() { return cms3.pfjets_mc_motherp4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfjets_mc_p4() { return cms3.pfjets_mc_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &photons_mc_motherp4() { return cms3.photons_mc_motherp4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &photons_mc_p4() { return cms3.photons_mc_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_conv_pos_p4() { return cms3.els_conv_pos_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_inner_position() { return cms3.els_inner_position(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_mc_patMatch_p4() { return cms3.els_mc_patMatch_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_outer_position() { return cms3.els_outer_position(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_p4() { return cms3.els_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_p4In() { return cms3.els_p4In(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_p4Out() { return cms3.els_p4Out(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_trk_p4() { return cms3.els_trk_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_trk_vertex_p4() { return cms3.els_trk_vertex_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &els_vertex_p4() { return cms3.els_vertex_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genjets_p4NoMuNoNu() { return cms3.genjets_p4NoMuNoNu(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genps_p4() { return cms3.genps_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genps_prod_vtx() { return cms3.genps_prod_vtx(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hyp_ll_p4() { return cms3.hyp_ll_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hyp_lt_p4() { return cms3.hyp_lt_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &hyp_p4() { return cms3.hyp_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_gfit_p4() { return cms3.mus_gfit_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_gfit_vertex_p4() { return cms3.mus_gfit_vertex_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_mc_patMatch_p4() { return cms3.mus_mc_patMatch_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_p4() { return cms3.mus_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_pfp4() { return cms3.mus_pfp4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_sta_p4() { return cms3.mus_sta_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_sta_vertex_p4() { return cms3.mus_sta_vertex_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_trk_p4() { return cms3.mus_trk_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &mus_vertex_p4() { return cms3.mus_vertex_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfcands_p4() { return cms3.pfcands_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &pfjets_p4() { return cms3.pfjets_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &taus_pf_lead_chargecand_p4() { return cms3.taus_pf_lead_chargecand_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &taus_pf_lead_neutrcand_p4() { return cms3.taus_pf_lead_neutrcand_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &taus_pf_p4() { return cms3.taus_pf_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &photons_p4() { return cms3.photons_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &svs_p4() { return cms3.svs_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &svs_position() { return cms3.svs_position(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &ak8jets_p4() { return cms3.ak8jets_p4(); }
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &vtxs_position() { return cms3.vtxs_position(); }
	vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &genps_lepdaughter_p4() { return cms3.genps_lepdaughter_p4(); }
	vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &hlt_trigObjs_p4() { return cms3.hlt_trigObjs_p4(); }
	vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &taus_pf_isocands_p4() { return cms3.taus_pf_isocands_p4(); }
	vector<vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > > &taus_pf_signalcands_p4() { return cms3.taus_pf_signalcands_p4(); }
	vector<float> &evt_bs_covMatrix() { return cms3.evt_bs_covMatrix(); }
	vector<float> &els_mc3dr() { return cms3.els_mc3dr(); }
	vector<float> &els_mcdr() { return cms3.els_mcdr(); }
	vector<float> &mus_mc3dr() { return cms3.mus_mc3dr(); }
	vector<float> &mus_mcdr() { return cms3.mus_mcdr(); }
	vector<float> &pfjets_mc3dr() { return cms3.pfjets_mc3dr(); }
	vector<float> &pfjets_mcdr() { return cms3.pfjets_mcdr(); }
	vector<float> &pfjets_mc_emEnergy() { return cms3.pfjets_mc_emEnergy(); }
	vector<float> &pfjets_mc_gpdr() { return cms3.pfjets_mc_gpdr(); }
	vector<float> &pfjets_mc_hadEnergy() { return cms3.pfjets_mc_hadEnergy(); }
	vector<float> &pfjets_mc_invEnergy() { return cms3.pfjets_mc_invEnergy(); }
	vector<float> &pfjets_mc_otherEnergy() { return cms3.pfjets_mc_otherEnergy(); }
	vector<float> &photons_mc3dr() { return cms3.photons_mc3dr(); }
	vector<float> &photons_mcdr() { return cms3.photons_mcdr(); }
	vector<float> &els_chi2() { return cms3.els_chi2(); }
	vector<float> &els_ckf_chi2() { return cms3.els_ckf_chi2(); }
	vector<float> &els_ckf_ndof() { return cms3.els_ckf_ndof(); }
	vector<float> &els_conv_dcot() { return cms3.els_conv_dcot(); }
	vector<float> &els_conv_dist() { return cms3.els_conv_dist(); }
	vector<float> &els_conv_old_dcot() { return cms3.els_conv_old_dcot(); }
	vector<float> &els_conv_old_dist() { return cms3.els_conv_old_dist(); }
	vector<float> &els_conv_old_radius() { return cms3.els_conv_old_radius(); }
	vector<float> &els_conv_radius() { return cms3.els_conv_radius(); }
	vector<float> &els_d0() { return cms3.els_d0(); }
	vector<float> &els_d0Err() { return cms3.els_d0Err(); }
	vector<float> &els_d0corr() { return cms3.els_d0corr(); }
	vector<float> &els_d0corrPhi() { return cms3.els_d0corrPhi(); }
	vector<float> &els_d0phiCov() { return cms3.els_d0phiCov(); }
	vector<float> &els_dEtaIn() { return cms3.els_dEtaIn(); }
	vector<float> &els_dEtaOut() { return cms3.els_dEtaOut(); }
	vector<float> &els_dPhiIn() { return cms3.els_dPhiIn(); }
	vector<float> &els_dPhiInPhiOut() { return cms3.els_dPhiInPhiOut(); }
	vector<float> &els_dPhiOut() { return cms3.els_dPhiOut(); }
	vector<float> &els_deltaEtaEleClusterTrackAtCalo() { return cms3.els_deltaEtaEleClusterTrackAtCalo(); }
	vector<float> &els_deltaPhiEleClusterTrackAtCalo() { return cms3.els_deltaPhiEleClusterTrackAtCalo(); }
	vector<float> &els_dxyPV() { return cms3.els_dxyPV(); }
	vector<float> &els_dzPV() { return cms3.els_dzPV(); }
	vector<float> &els_e1x5() { return cms3.els_e1x5(); }
	vector<float> &els_e1x5_full5x5() { return cms3.els_e1x5_full5x5(); }
	vector<float> &els_e2x5Max() { return cms3.els_e2x5Max(); }
	vector<float> &els_e2x5Max_full5x5() { return cms3.els_e2x5Max_full5x5(); }
	vector<float> &els_e3x3() { return cms3.els_e3x3(); }
	vector<float> &els_e5x5() { return cms3.els_e5x5(); }
	vector<float> &els_e5x5_full5x5() { return cms3.els_e5x5_full5x5(); }
	vector<float> &els_eMax() { return cms3.els_eMax(); }
	vector<float> &els_eOverPIn() { return cms3.els_eOverPIn(); }
	vector<float> &els_eOverPOut() { return cms3.els_eOverPOut(); }
	vector<float> &els_eSC() { return cms3.els_eSC(); }
	vector<float> &els_eSCPresh() { return cms3.els_eSCPresh(); }
	vector<float> &els_eSCRaw() { return cms3.els_eSCRaw(); }
	vector<float> &els_eSeed() { return cms3.els_eSeed(); }
	vector<float> &els_eSeedOverPIn() { return cms3.els_eSeedOverPIn(); }
	vector<float> &els_eSeedOverPOut() { return cms3.els_eSeedOverPOut(); }
	vector<float> &els_ecalEnergy() { return cms3.els_ecalEnergy(); }
	vector<float> &els_ecalEnergyError() { return cms3.els_ecalEnergyError(); }
	vector<float> &els_ecalIso() { return cms3.els_ecalIso(); }
	vector<float> &els_ecalIso04() { return cms3.els_ecalIso04(); }
	vector<float> &els_etaErr() { return cms3.els_etaErr(); }
	vector<float> &els_etaSC() { return cms3.els_etaSC(); }
	vector<float> &els_etaSCwidth() { return cms3.els_etaSCwidth(); }
	vector<float> &els_fbrem() { return cms3.els_fbrem(); }
	vector<float> &els_hOverE() { return cms3.els_hOverE(); }
	vector<float> &els_hOverEBC() { return cms3.els_hOverEBC(); }
	vector<float> &els_hcalDepth1OverEcal() { return cms3.els_hcalDepth1OverEcal(); }
	vector<float> &els_hcalDepth1TowerSumEt() { return cms3.els_hcalDepth1TowerSumEt(); }
	vector<float> &els_hcalDepth1TowerSumEt04() { return cms3.els_hcalDepth1TowerSumEt04(); }
	vector<float> &els_hcalDepth2OverEcal() { return cms3.els_hcalDepth2OverEcal(); }
	vector<float> &els_hcalDepth2TowerSumEt() { return cms3.els_hcalDepth2TowerSumEt(); }
	vector<float> &els_hcalDepth2TowerSumEt04() { return cms3.els_hcalDepth2TowerSumEt04(); }
	vector<float> &els_hcalIso() { return cms3.els_hcalIso(); }
	vector<float> &els_hcalIso04() { return cms3.els_hcalIso04(); }
	vector<float> &els_ip3d() { return cms3.els_ip3d(); }
	vector<float> &els_ip3derr() { return cms3.els_ip3derr(); }
	vector<float> &els_iso03_pf() { return cms3.els_iso03_pf(); }
	vector<float> &els_iso03_pf2012_ch() { return cms3.els_iso03_pf2012_ch(); }
	vector<float> &els_iso03_pf2012_em() { return cms3.els_iso03_pf2012_em(); }
	vector<float> &els_iso03_pf2012ext_ch() { return cms3.els_iso03_pf2012ext_ch(); }
	vector<float> &els_iso03_pf2012ext_em() { return cms3.els_iso03_pf2012ext_em(); }
	vector<float> &els_iso03_pf2012ext_nh() { return cms3.els_iso03_pf2012ext_nh(); }
	vector<float> &els_iso03_pf2012_nh() { return cms3.els_iso03_pf2012_nh(); }
	vector<float> &els_iso03_pf_ch() { return cms3.els_iso03_pf_ch(); }
	vector<float> &els_iso03_pf_gamma05() { return cms3.els_iso03_pf_gamma05(); }
	vector<float> &els_iso03_pf_nhad05() { return cms3.els_iso03_pf_nhad05(); }
	vector<float> &els_iso04_pf() { return cms3.els_iso04_pf(); }
	vector<float> &els_iso04_pf2012_ch() { return cms3.els_iso04_pf2012_ch(); }
	vector<float> &els_iso04_pf2012_em() { return cms3.els_iso04_pf2012_em(); }
	vector<float> &els_iso04_pf2012ext_ch() { return cms3.els_iso04_pf2012ext_ch(); }
	vector<float> &els_iso04_pf2012ext_em() { return cms3.els_iso04_pf2012ext_em(); }
	vector<float> &els_iso04_pf2012ext_nh() { return cms3.els_iso04_pf2012ext_nh(); }
	vector<float> &els_iso04_pf2012_nh() { return cms3.els_iso04_pf2012_nh(); }
	vector<float> &els_iso04_pf_ch() { return cms3.els_iso04_pf_ch(); }
	vector<float> &els_iso04_pf_gamma05() { return cms3.els_iso04_pf_gamma05(); }
	vector<float> &els_iso04_pf_nhad05() { return cms3.els_iso04_pf_nhad05(); }
	vector<float> &els_layer1_charge() { return cms3.els_layer1_charge(); }
	vector<float> &els_lh() { return cms3.els_lh(); }
	vector<float> &els_mass() { return cms3.els_mass(); }
	vector<float> &els_mc_patMatch_dr() { return cms3.els_mc_patMatch_dr(); }
	vector<float> &els_mva() { return cms3.els_mva(); }
	vector<float> &els_ndof() { return cms3.els_ndof(); }
	vector<float> &els_pfChargedHadronIso() { return cms3.els_pfChargedHadronIso(); }
	vector<float> &els_pfNeutralHadronIso() { return cms3.els_pfNeutralHadronIso(); }
	vector<float> &els_pfPUIso() { return cms3.els_pfPUIso(); }
	vector<float> &els_pfPhotonIso() { return cms3.els_pfPhotonIso(); }
	vector<float> &els_phiErr() { return cms3.els_phiErr(); }
	vector<float> &els_phiSC() { return cms3.els_phiSC(); }
	vector<float> &els_phiSCwidth() { return cms3.els_phiSCwidth(); }
	vector<float> &els_ptErr() { return cms3.els_ptErr(); }
	vector<float> &els_ptErrGsf() { return cms3.els_ptErrGsf(); }
	vector<float> &els_r9() { return cms3.els_r9(); }
	vector<float> &els_r9_full5x5() { return cms3.els_r9_full5x5(); }
	vector<float> &els_sigmaEtaEta() { return cms3.els_sigmaEtaEta(); }
	vector<float> &els_sigmaEtaEta_full5x5() { return cms3.els_sigmaEtaEta_full5x5(); }
	vector<float> &els_sigmaIEtaIEta() { return cms3.els_sigmaIEtaIEta(); }
	vector<float> &els_sigmaIEtaIEtaSC() { return cms3.els_sigmaIEtaIEtaSC(); }
	vector<float> &els_sigmaIEtaIEta_full5x5() { return cms3.els_sigmaIEtaIEta_full5x5(); }
	vector<float> &els_sigmaIEtaIPhi() { return cms3.els_sigmaIEtaIPhi(); }
	vector<float> &els_sigmaIPhiIPhi() { return cms3.els_sigmaIPhiIPhi(); }
	vector<float> &els_sigmaIPhiIPhiSC() { return cms3.els_sigmaIPhiIPhiSC(); }
	vector<float> &els_sigmaIPhiIPhi_full5x5() { return cms3.els_sigmaIPhiIPhi_full5x5(); }
	vector<float> &els_sigmaIphiIphi() { return cms3.els_sigmaIphiIphi(); }
	vector<float> &els_sigmaPhiPhi() { return cms3.els_sigmaPhiPhi(); }
	vector<float> &els_tkIso() { return cms3.els_tkIso(); }
	vector<float> &els_tkIso04() { return cms3.els_tkIso04(); }
	vector<float> &els_trackMomentumError() { return cms3.els_trackMomentumError(); }
	vector<float> &els_trkdr() { return cms3.els_trkdr(); }
	vector<float> &els_trkshFrac() { return cms3.els_trkshFrac(); }
	vector<float> &els_z0() { return cms3.els_z0(); }
	vector<float> &els_z0Err() { return cms3.els_z0Err(); }
	vector<float> &els_z0corr() { return cms3.els_z0corr(); }
	vector<float> &genps_charge() { return cms3.genps_charge(); }
	vector<float> &genps_iso() { return cms3.genps_iso(); }
	vector<float> &genps_mass() { return cms3.genps_mass(); }
	vector<float> &mus_backToBackCompat() { return cms3.mus_backToBackCompat(); }
	vector<float> &mus_best_dxyPV() { return cms3.mus_best_dxyPV(); }
	vector<float> &mus_best_dzPV() { return cms3.mus_best_dzPV(); }
	vector<float> &mus_caloCompatibility() { return cms3.mus_caloCompatibility(); }
	vector<float> &mus_chi2() { return cms3.mus_chi2(); }
	vector<float> &mus_chi2LocalMomentum() { return cms3.mus_chi2LocalMomentum(); }
	vector<float> &mus_chi2LocalPosition() { return cms3.mus_chi2LocalPosition(); }
	vector<float> &mus_cosmicCompat() { return cms3.mus_cosmicCompat(); }
	vector<float> &mus_d0() { return cms3.mus_d0(); }
	vector<float> &mus_d0Err() { return cms3.mus_d0Err(); }
	vector<float> &mus_d0corr() { return cms3.mus_d0corr(); }
	vector<float> &mus_d0corrPhi() { return cms3.mus_d0corrPhi(); }
	vector<float> &mus_d0phiCov() { return cms3.mus_d0phiCov(); }
	vector<float> &mus_dxyPV() { return cms3.mus_dxyPV(); }
	vector<float> &mus_dzPV() { return cms3.mus_dzPV(); }
	vector<float> &mus_ecal_time() { return cms3.mus_ecal_time(); }
	vector<float> &mus_ecal_timeError() { return cms3.mus_ecal_timeError(); }
	vector<float> &mus_e_em() { return cms3.mus_e_em(); }
	vector<float> &mus_e_emS9() { return cms3.mus_e_emS9(); }
	vector<float> &mus_e_had() { return cms3.mus_e_had(); }
	vector<float> &mus_e_hadS9() { return cms3.mus_e_hadS9(); }
	vector<float> &mus_e_ho() { return cms3.mus_e_ho(); }
	vector<float> &mus_e_hoS9() { return cms3.mus_e_hoS9(); }
	vector<float> &mus_emMax() { return cms3.mus_emMax(); }
	vector<float> &mus_emS25() { return cms3.mus_emS25(); }
	vector<float> &mus_etaErr() { return cms3.mus_etaErr(); }
	vector<float> &mus_gfit_chi2() { return cms3.mus_gfit_chi2(); }
	vector<float> &mus_gfit_d0() { return cms3.mus_gfit_d0(); }
	vector<float> &mus_gfit_d0Err() { return cms3.mus_gfit_d0Err(); }
	vector<float> &mus_gfit_d0corr() { return cms3.mus_gfit_d0corr(); }
	vector<float> &mus_gfit_d0corrPhi() { return cms3.mus_gfit_d0corrPhi(); }
	vector<float> &mus_gfit_d0phiCov() { return cms3.mus_gfit_d0phiCov(); }
	vector<float> &mus_gfit_ndof() { return cms3.mus_gfit_ndof(); }
	vector<float> &mus_gfit_qoverp() { return cms3.mus_gfit_qoverp(); }
	vector<float> &mus_gfit_qoverpError() { return cms3.mus_gfit_qoverpError(); }
	vector<float> &mus_gfit_z0() { return cms3.mus_gfit_z0(); }
	vector<float> &mus_gfit_z0Err() { return cms3.mus_gfit_z0Err(); }
	vector<float> &mus_gfit_z0corr() { return cms3.mus_gfit_z0corr(); }
	vector<float> &mus_glbKink() { return cms3.mus_glbKink(); }
	vector<float> &mus_glbTrackProbability() { return cms3.mus_glbTrackProbability(); }
	vector<float> &mus_globalDeltaEtaPhi() { return cms3.mus_globalDeltaEtaPhi(); }
	vector<float> &mus_hadMax() { return cms3.mus_hadMax(); }
	vector<float> &mus_hcal_time() { return cms3.mus_hcal_time(); }
	vector<float> &mus_hcal_timeError() { return cms3.mus_hcal_timeError(); }
	vector<float> &mus_ip3d() { return cms3.mus_ip3d(); }
	vector<float> &mus_ip3derr() { return cms3.mus_ip3derr(); }
	vector<float> &mus_iso03_emEt() { return cms3.mus_iso03_emEt(); }
	vector<float> &mus_iso03_hadEt() { return cms3.mus_iso03_hadEt(); }
	vector<float> &mus_iso03_hoEt() { return cms3.mus_iso03_hoEt(); }
	vector<float> &mus_iso03_sumPt() { return cms3.mus_iso03_sumPt(); }
	vector<float> &mus_iso05_emEt() { return cms3.mus_iso05_emEt(); }
	vector<float> &mus_iso05_hadEt() { return cms3.mus_iso05_hadEt(); }
	vector<float> &mus_iso05_hoEt() { return cms3.mus_iso05_hoEt(); }
	vector<float> &mus_iso05_sumPt() { return cms3.mus_iso05_sumPt(); }
	vector<float> &mus_isoMeanDRR03_pf_ChargedHadronPt() { return cms3.mus_isoMeanDRR03_pf_ChargedHadronPt(); }
	vector<float> &mus_isoMeanDRR03_pf_ChargedParticlePt() { return cms3.mus_isoMeanDRR03_pf_ChargedParticlePt(); }
	vector<float> &mus_isoMeanDRR03_pf_NeutralHadronEt() { return cms3.mus_isoMeanDRR03_pf_NeutralHadronEt(); }
	vector<float> &mus_isoMeanDRR03_pf_NeutralHadronEtHighThreshold() { return cms3.mus_isoMeanDRR03_pf_NeutralHadronEtHighThreshold(); }
	vector<float> &mus_isoMeanDRR03_pf_PUPt() { return cms3.mus_isoMeanDRR03_pf_PUPt(); }
	vector<float> &mus_isoMeanDRR03_pf_PhotonEt() { return cms3.mus_isoMeanDRR03_pf_PhotonEt(); }
	vector<float> &mus_isoMeanDRR03_pf_PhotonEtHighThreshold() { return cms3.mus_isoMeanDRR03_pf_PhotonEtHighThreshold(); }
	vector<float> &mus_isoMeanDRR04_pf_ChargedHadronPt() { return cms3.mus_isoMeanDRR04_pf_ChargedHadronPt(); }
	vector<float> &mus_isoMeanDRR04_pf_ChargedParticlePt() { return cms3.mus_isoMeanDRR04_pf_ChargedParticlePt(); }
	vector<float> &mus_isoMeanDRR04_pf_NeutralHadronEt() { return cms3.mus_isoMeanDRR04_pf_NeutralHadronEt(); }
	vector<float> &mus_isoMeanDRR04_pf_NeutralHadronEtHighThreshold() { return cms3.mus_isoMeanDRR04_pf_NeutralHadronEtHighThreshold(); }
	vector<float> &mus_isoMeanDRR04_pf_PUPt() { return cms3.mus_isoMeanDRR04_pf_PUPt(); }
	vector<float> &mus_isoMeanDRR04_pf_PhotonEt() { return cms3.mus_isoMeanDRR04_pf_PhotonEt(); }
	vector<float> &mus_isoMeanDRR04_pf_PhotonEtHighThreshold() { return cms3.mus_isoMeanDRR04_pf_PhotonEtHighThreshold(); }
	vector<float> &mus_isoR03_pf_ChargedHadronPt() { return cms3.mus_isoR03_pf_ChargedHadronPt(); }
	vector<float> &mus_isoR03_pf_ChargedParticlePt() { return cms3.mus_isoR03_pf_ChargedParticlePt(); }
	vector<float> &mus_isoR03_pf_NeutralHadronEt() { return cms3.mus_isoR03_pf_NeutralHadronEt(); }
	vector<float> &mus_isoR03_pf_NeutralHadronEtHighThreshold() { return cms3.mus_isoR03_pf_NeutralHadronEtHighThreshold(); }
	vector<float> &mus_isoR03_pf_PUPt() { return cms3.mus_isoR03_pf_PUPt(); }
	vector<float> &mus_isoR03_pf_PhotonEt() { return cms3.mus_isoR03_pf_PhotonEt(); }
	vector<float> &mus_isoR03_pf_PhotonEtHighThreshold() { return cms3.mus_isoR03_pf_PhotonEtHighThreshold(); }
	vector<float> &mus_isoR04_pf_ChargedHadronPt() { return cms3.mus_isoR04_pf_ChargedHadronPt(); }
	vector<float> &mus_isoR04_pf_ChargedParticlePt() { return cms3.mus_isoR04_pf_ChargedParticlePt(); }
	vector<float> &mus_isoR04_pf_NeutralHadronEt() { return cms3.mus_isoR04_pf_NeutralHadronEt(); }
	vector<float> &mus_isoR04_pf_NeutralHadronEtHighThreshold() { return cms3.mus_isoR04_pf_NeutralHadronEtHighThreshold(); }
	vector<float> &mus_isoR04_pf_PUPt() { return cms3.mus_isoR04_pf_PUPt(); }
	vector<float> &mus_isoR04_pf_PhotonEt() { return cms3.mus_isoR04_pf_PhotonEt(); }
	vector<float> &mus_isoR04_pf_PhotonEtHighThreshold() { return cms3.mus_isoR04_pf_PhotonEtHighThreshold(); }
	vector<float> &mus_isoSumDRR03_pf_ChargedHadronPt() { return cms3.mus_isoSumDRR03_pf_ChargedHadronPt(); }
	vector<float> &mus_isoSumDRR03_pf_ChargedParticlePt() { return cms3.mus_isoSumDRR03_pf_ChargedParticlePt(); }
	vector<float> &mus_isoSumDRR03_pf_NeutralHadronEt() { return cms3.mus_isoSumDRR03_pf_NeutralHadronEt(); }
	vector<float> &mus_isoSumDRR03_pf_NeutralHadronEtHighThreshold() { return cms3.mus_isoSumDRR03_pf_NeutralHadronEtHighThreshold(); }
	vector<float> &mus_isoSumDRR03_pf_PUPt() { return cms3.mus_isoSumDRR03_pf_PUPt(); }
	vector<float> &mus_isoSumDRR03_pf_PhotonEt() { return cms3.mus_isoSumDRR03_pf_PhotonEt(); }
	vector<float> &mus_isoSumDRR03_pf_PhotonEtHighThreshold() { return cms3.mus_isoSumDRR03_pf_PhotonEtHighThreshold(); }
	vector<float> &mus_isoSumDRR04_pf_ChargedHadronPt() { return cms3.mus_isoSumDRR04_pf_ChargedHadronPt(); }
	vector<float> &mus_isoSumDRR04_pf_ChargedParticlePt() { return cms3.mus_isoSumDRR04_pf_ChargedParticlePt(); }
	vector<float> &mus_isoSumDRR04_pf_NeutralHadronEt() { return cms3.mus_isoSumDRR04_pf_NeutralHadronEt(); }
	vector<float> &mus_isoSumDRR04_pf_NeutralHadronEtHighThreshold() { return cms3.mus_isoSumDRR04_pf_NeutralHadronEtHighThreshold(); }
	vector<float> &mus_isoSumDRR04_pf_PUPt() { return cms3.mus_isoSumDRR04_pf_PUPt(); }
	vector<float> &mus_isoSumDRR04_pf_PhotonEt() { return cms3.mus_isoSumDRR04_pf_PhotonEt(); }
	vector<float> &mus_isoSumDRR04_pf_PhotonEtHighThreshold() { return cms3.mus_isoSumDRR04_pf_PhotonEtHighThreshold(); }
	vector<float> &mus_iso_ecalvetoDep() { return cms3.mus_iso_ecalvetoDep(); }
	vector<float> &mus_iso_hcalvetoDep() { return cms3.mus_iso_hcalvetoDep(); }
	vector<float> &mus_iso_hovetoDep() { return cms3.mus_iso_hovetoDep(); }
	vector<float> &mus_iso_trckvetoDep() { return cms3.mus_iso_trckvetoDep(); }
	vector<float> &mus_localDistance() { return cms3.mus_localDistance(); }
	vector<float> &mus_mass() { return cms3.mus_mass(); }
	vector<float> &mus_mc_patMatch_dr() { return cms3.mus_mc_patMatch_dr(); }
	vector<float> &mus_ndof() { return cms3.mus_ndof(); }
	vector<float> &mus_overlapCompat() { return cms3.mus_overlapCompat(); }
	vector<float> &mus_phiErr() { return cms3.mus_phiErr(); }
	vector<float> &mus_ptErr() { return cms3.mus_ptErr(); }
	vector<float> &mus_qoverp() { return cms3.mus_qoverp(); }
	vector<float> &mus_qoverpError() { return cms3.mus_qoverpError(); }
	vector<float> &mus_segmCompatibility() { return cms3.mus_segmCompatibility(); }
	vector<float> &mus_staRelChi2() { return cms3.mus_staRelChi2(); }
	vector<float> &mus_sta_chi2() { return cms3.mus_sta_chi2(); }
	vector<float> &mus_sta_d0() { return cms3.mus_sta_d0(); }
	vector<float> &mus_sta_d0Err() { return cms3.mus_sta_d0Err(); }
	vector<float> &mus_sta_d0corr() { return cms3.mus_sta_d0corr(); }
	vector<float> &mus_sta_d0corrPhi() { return cms3.mus_sta_d0corrPhi(); }
	vector<float> &mus_sta_d0phiCov() { return cms3.mus_sta_d0phiCov(); }
	vector<float> &mus_sta_ndof() { return cms3.mus_sta_ndof(); }
	vector<float> &mus_sta_qoverp() { return cms3.mus_sta_qoverp(); }
	vector<float> &mus_sta_qoverpError() { return cms3.mus_sta_qoverpError(); }
	vector<float> &mus_sta_z0() { return cms3.mus_sta_z0(); }
	vector<float> &mus_sta_z0Err() { return cms3.mus_sta_z0Err(); }
	vector<float> &mus_sta_z0corr() { return cms3.mus_sta_z0corr(); }
	vector<float> &mus_timeAtIpInOut() { return cms3.mus_timeAtIpInOut(); }
	vector<float> &mus_timeAtIpInOutErr() { return cms3.mus_timeAtIpInOutErr(); }
	vector<float> &mus_timeAtIpOutIn() { return cms3.mus_timeAtIpOutIn(); }
	vector<float> &mus_timeAtIpOutInErr() { return cms3.mus_timeAtIpOutInErr(); }
	vector<float> &mus_timeCompat() { return cms3.mus_timeCompat(); }
	vector<float> &mus_tower() { return cms3.mus_tower(); }
	vector<float> &mus_towerS9() { return cms3.mus_towerS9(); }
	vector<float> &mus_trkKink() { return cms3.mus_trkKink(); }
	vector<float> &mus_trkRelChi2() { return cms3.mus_trkRelChi2(); }
	vector<float> &mus_vertexCompat() { return cms3.mus_vertexCompat(); }
	vector<float> &mus_vertexphi() { return cms3.mus_vertexphi(); }
	vector<float> &mus_z0() { return cms3.mus_z0(); }
	vector<float> &mus_z0Err() { return cms3.mus_z0Err(); }
	vector<float> &mus_z0corr() { return cms3.mus_z0corr(); }
	vector<float> &pfcands_dz() { return cms3.pfcands_dz(); }
	vector<float> &pfcands_mass() { return cms3.pfcands_mass(); }
	vector<float> &pfjets_area() { return cms3.pfjets_area(); }
	vector<float> &pfjets_chargedEmE() { return cms3.pfjets_chargedEmE(); }
	vector<float> &pfjets_chargedHadronE() { return cms3.pfjets_chargedHadronE(); }
	vector<float> &pfjets_combinedInclusiveSecondaryVertexV2BJetTag() { return cms3.pfjets_combinedInclusiveSecondaryVertexV2BJetTag(); }
	vector<float> &pfjets_combinedMVABJetTag() { return cms3.pfjets_combinedMVABJetTag(); }
	vector<float> &pfjets_cor() { return cms3.pfjets_cor(); }
	vector<float> &pfjets_corL1L2L3() { return cms3.pfjets_corL1L2L3(); }
	vector<float> &pfjets_electronE() { return cms3.pfjets_electronE(); }
	vector<float> &pfjets_hfEmE() { return cms3.pfjets_hfEmE(); }
	vector<float> &pfjets_hfHadronE() { return cms3.pfjets_hfHadronE(); }
	vector<float> &pfjets_jetBProbabilityBJetTag() { return cms3.pfjets_jetBProbabilityBJetTag(); }
	vector<float> &pfjets_jetProbabilityBJetTag() { return cms3.pfjets_jetProbabilityBJetTag(); }
	vector<float> &pfjets_mass() { return cms3.pfjets_mass(); }
	vector<float> &pfjets_muonE() { return cms3.pfjets_muonE(); }
	vector<float> &pfjets_neutralEmE() { return cms3.pfjets_neutralEmE(); }
	vector<float> &pfjets_neutralHadronE() { return cms3.pfjets_neutralHadronE(); }
	vector<float> &pfjets_pfCombinedSecondaryVertexBJetTag() { return cms3.pfjets_pfCombinedSecondaryVertexBJetTag(); }
	vector<float> &pfjets_photonE() { return cms3.pfjets_photonE(); }
	vector<float> &pfjets_pileupJetId() { return cms3.pfjets_pileupJetId(); }
	vector<float> &pfjets_simpleSecondaryVertexHighEffBJetTag() { return cms3.pfjets_simpleSecondaryVertexHighEffBJetTag(); }
	vector<float> &pfjets_simpleSecondaryVertexHighPurBJetTags() { return cms3.pfjets_simpleSecondaryVertexHighPurBJetTags(); }
	vector<float> &pfjets_trackCountingHighEffBJetTag() { return cms3.pfjets_trackCountingHighEffBJetTag(); }
	vector<float> &pfjets_trackCountingHighPurBJetTag() { return cms3.pfjets_trackCountingHighPurBJetTag(); }
	vector<float> &pfjets_undoJEC() { return cms3.pfjets_undoJEC(); }
	vector<float> &taus_pf_againstElectronDeadECAL() { return cms3.taus_pf_againstElectronDeadECAL(); }
	vector<float> &taus_pf_againstElectronLoose() { return cms3.taus_pf_againstElectronLoose(); }
	vector<float> &taus_pf_againstElectronMedium() { return cms3.taus_pf_againstElectronMedium(); }
	vector<float> &taus_pf_againstElectronTight() { return cms3.taus_pf_againstElectronTight(); }
	vector<float> &taus_pf_againstMuonLoose() { return cms3.taus_pf_againstMuonLoose(); }
	vector<float> &taus_pf_againstMuonLoose2() { return cms3.taus_pf_againstMuonLoose2(); }
	vector<float> &taus_pf_againstMuonLoose3() { return cms3.taus_pf_againstMuonLoose3(); }
	vector<float> &taus_pf_againstMuonMedium() { return cms3.taus_pf_againstMuonMedium(); }
	vector<float> &taus_pf_againstMuonMedium2() { return cms3.taus_pf_againstMuonMedium2(); }
	vector<float> &taus_pf_againstMuonTight() { return cms3.taus_pf_againstMuonTight(); }
	vector<float> &taus_pf_againstMuonTight2() { return cms3.taus_pf_againstMuonTight2(); }
	vector<float> &taus_pf_againstMuonTight3() { return cms3.taus_pf_againstMuonTight3(); }
	vector<float> &taus_pf_byCombinedIsolationDeltaBetaCorrRaw() { return cms3.taus_pf_byCombinedIsolationDeltaBetaCorrRaw(); }
	vector<float> &taus_pf_byCombinedIsolationDeltaBetaCorrRaw3Hits() { return cms3.taus_pf_byCombinedIsolationDeltaBetaCorrRaw3Hits(); }
	vector<float> &taus_pf_byDecayModeFinding() { return cms3.taus_pf_byDecayModeFinding(); }
	vector<float> &taus_pf_byLooseCombinedIsolationDeltaBetaCorr() { return cms3.taus_pf_byLooseCombinedIsolationDeltaBetaCorr(); }
	vector<float> &taus_pf_byLooseCombinedIsolationDeltaBetaCorr3Hits() { return cms3.taus_pf_byLooseCombinedIsolationDeltaBetaCorr3Hits(); }
	vector<float> &taus_pf_byMediumCombinedIsolationDeltaBetaCorr() { return cms3.taus_pf_byMediumCombinedIsolationDeltaBetaCorr(); }
	vector<float> &taus_pf_byMediumCombinedIsolationDeltaBetaCorr3Hits() { return cms3.taus_pf_byMediumCombinedIsolationDeltaBetaCorr3Hits(); }
	vector<float> &taus_pf_byTightCombinedIsolationDeltaBetaCorr() { return cms3.taus_pf_byTightCombinedIsolationDeltaBetaCorr(); }
	vector<float> &taus_pf_byTightCombinedIsolationDeltaBetaCorr3Hits() { return cms3.taus_pf_byTightCombinedIsolationDeltaBetaCorr3Hits(); }
	vector<float> &taus_pf_byVLooseCombinedIsolationDeltaBetaCorr() { return cms3.taus_pf_byVLooseCombinedIsolationDeltaBetaCorr(); }
	vector<float> &taus_pf_mass() { return cms3.taus_pf_mass(); }
	vector<float> &photons_chargedHadronIso() { return cms3.photons_chargedHadronIso(); }
	vector<float> &photons_e1x5() { return cms3.photons_e1x5(); }
	vector<float> &photons_e2x5Max() { return cms3.photons_e2x5Max(); }
	vector<float> &photons_e3x3() { return cms3.photons_e3x3(); }
	vector<float> &photons_e5x5() { return cms3.photons_e5x5(); }
	vector<float> &photons_ecalIso03() { return cms3.photons_ecalIso03(); }
	vector<float> &photons_ecalIso04() { return cms3.photons_ecalIso04(); }
	vector<float> &photons_full3x3_e3x3() { return cms3.photons_full3x3_e3x3(); }
	vector<float> &photons_full5x5_e1x5() { return cms3.photons_full5x5_e1x5(); }
	vector<float> &photons_full5x5_e2x5Max() { return cms3.photons_full5x5_e2x5Max(); }
	vector<float> &photons_full5x5_e5x5() { return cms3.photons_full5x5_e5x5(); }
	vector<float> &photons_full5x5_hOverE() { return cms3.photons_full5x5_hOverE(); }
	vector<float> &photons_full5x5_hOverEtowBC() { return cms3.photons_full5x5_hOverEtowBC(); }
	vector<float> &photons_full5x5_r9() { return cms3.photons_full5x5_r9(); }
	vector<float> &photons_full5x5_sigmaEtaEta() { return cms3.photons_full5x5_sigmaEtaEta(); }
	vector<float> &photons_full5x5_sigmaIEtaIEta() { return cms3.photons_full5x5_sigmaIEtaIEta(); }
	vector<float> &photons_hOverE() { return cms3.photons_hOverE(); }
	vector<float> &photons_hcalDepth1TowerSumEtBcConeDR03() { return cms3.photons_hcalDepth1TowerSumEtBcConeDR03(); }
	vector<float> &photons_hcalDepth1TowerSumEtBcConeDR04() { return cms3.photons_hcalDepth1TowerSumEtBcConeDR04(); }
	vector<float> &photons_hcalDepth2TowerSumEtBcConeDR03() { return cms3.photons_hcalDepth2TowerSumEtBcConeDR03(); }
	vector<float> &photons_hcalDepth2TowerSumEtBcConeDR04() { return cms3.photons_hcalDepth2TowerSumEtBcConeDR04(); }
	vector<float> &photons_hcalIso03() { return cms3.photons_hcalIso03(); }
	vector<float> &photons_hcalIso04() { return cms3.photons_hcalIso04(); }
	vector<float> &photons_hcalTowerSumEtBcConeDR03() { return cms3.photons_hcalTowerSumEtBcConeDR03(); }
	vector<float> &photons_hcalTowerSumEtBcConeDR04() { return cms3.photons_hcalTowerSumEtBcConeDR04(); }
	vector<float> &photons_mass() { return cms3.photons_mass(); }
	vector<float> &photons_neutralHadronIso() { return cms3.photons_neutralHadronIso(); }
	vector<float> &photons_ntkIsoHollow03() { return cms3.photons_ntkIsoHollow03(); }
	vector<float> &photons_ntkIsoHollow04() { return cms3.photons_ntkIsoHollow04(); }
	vector<float> &photons_ntkIsoSolid03() { return cms3.photons_ntkIsoSolid03(); }
	vector<float> &photons_ntkIsoSolid04() { return cms3.photons_ntkIsoSolid04(); }
	vector<float> &photons_photonIso() { return cms3.photons_photonIso(); }
	vector<float> &photons_recoChargedHadronIso() { return cms3.photons_recoChargedHadronIso(); }
	vector<float> &photons_recoNeutralHadronIso() { return cms3.photons_recoNeutralHadronIso(); }
	vector<float> &photons_recoPhotonIso() { return cms3.photons_recoPhotonIso(); }
	vector<float> &photons_sigmaEtaEta() { return cms3.photons_sigmaEtaEta(); }
	vector<float> &photons_sigmaIEtaIEta() { return cms3.photons_sigmaIEtaIEta(); }
	vector<float> &photons_tkIsoHollow03() { return cms3.photons_tkIsoHollow03(); }
	vector<float> &photons_tkIsoHollow04() { return cms3.photons_tkIsoHollow04(); }
	vector<float> &photons_tkIsoSolid03() { return cms3.photons_tkIsoSolid03(); }
	vector<float> &photons_tkIsoSolid04() { return cms3.photons_tkIsoSolid04(); }
	vector<float> &puInfo_trueNumInteractions() { return cms3.puInfo_trueNumInteractions(); }
	vector<float> &convs_chi2() { return cms3.convs_chi2(); }
	vector<float> &convs_dl() { return cms3.convs_dl(); }
	vector<float> &convs_ndof() { return cms3.convs_ndof(); }
	vector<float> &svs_anglePV() { return cms3.svs_anglePV(); }
	vector<float> &svs_chi2() { return cms3.svs_chi2(); }
	vector<float> &svs_dist3Dsig() { return cms3.svs_dist3Dsig(); }
	vector<float> &svs_dist3Dval() { return cms3.svs_dist3Dval(); }
	vector<float> &svs_distXYsig() { return cms3.svs_distXYsig(); }
	vector<float> &svs_distXYval() { return cms3.svs_distXYval(); }
	vector<float> &svs_ndof() { return cms3.svs_ndof(); }
	vector<float> &svs_prob() { return cms3.svs_prob(); }
	vector<float> &svs_xError() { return cms3.svs_xError(); }
	vector<float> &svs_yError() { return cms3.svs_yError(); }
	vector<float> &svs_zError() { return cms3.svs_zError(); }
	vector<float> &ak8jets_area() { return cms3.ak8jets_area(); }
	vector<float> &ak8jets_chargedEmE() { return cms3.ak8jets_chargedEmE(); }
	vector<float> &ak8jets_chargedHadronE() { return cms3.ak8jets_chargedHadronE(); }
	vector<float> &ak8jets_combinedSecondaryVertexBJetTag() { return cms3.ak8jets_combinedSecondaryVertexBJetTag(); }
	vector<float> &ak8jets_electronE() { return cms3.ak8jets_electronE(); }
	vector<float> &ak8jets_filteredMass() { return cms3.ak8jets_filteredMass(); }
	vector<float> &ak8jets_hfEmE() { return cms3.ak8jets_hfEmE(); }
	vector<float> &ak8jets_hfHadronE() { return cms3.ak8jets_hfHadronE(); }
	vector<float> &ak8jets_jetBProbabilityBJetTag() { return cms3.ak8jets_jetBProbabilityBJetTag(); }
	vector<float> &ak8jets_jetProbabilityBJetTag() { return cms3.ak8jets_jetProbabilityBJetTag(); }
	vector<float> &ak8jets_mass() { return cms3.ak8jets_mass(); }
	vector<float> &ak8jets_muonE() { return cms3.ak8jets_muonE(); }
	vector<float> &ak8jets_nJettinessTau1() { return cms3.ak8jets_nJettinessTau1(); }
	vector<float> &ak8jets_nJettinessTau2() { return cms3.ak8jets_nJettinessTau2(); }
	vector<float> &ak8jets_nJettinessTau3() { return cms3.ak8jets_nJettinessTau3(); }
	vector<float> &ak8jets_neutralEmE() { return cms3.ak8jets_neutralEmE(); }
	vector<float> &ak8jets_neutralHadronE() { return cms3.ak8jets_neutralHadronE(); }
	vector<float> &ak8jets_photonE() { return cms3.ak8jets_photonE(); }
	vector<float> &ak8jets_pileupJetId() { return cms3.ak8jets_pileupJetId(); }
	vector<float> &ak8jets_prunedMass() { return cms3.ak8jets_prunedMass(); }
	vector<float> &ak8jets_qJetsVolatility() { return cms3.ak8jets_qJetsVolatility(); }
	vector<float> &ak8jets_simpleSecondaryVertexHighEffBJetTag() { return cms3.ak8jets_simpleSecondaryVertexHighEffBJetTag(); }
	vector<float> &ak8jets_simpleSecondaryVertexHighPurBJetTags() { return cms3.ak8jets_simpleSecondaryVertexHighPurBJetTags(); }
	vector<float> &ak8jets_topJetMass() { return cms3.ak8jets_topJetMass(); }
	vector<float> &ak8jets_trackCountingHighEffBJetTag() { return cms3.ak8jets_trackCountingHighEffBJetTag(); }
	vector<float> &ak8jets_trackCountingHighPurBJetTag() { return cms3.ak8jets_trackCountingHighPurBJetTag(); }
	vector<float> &ak8jets_trimmedMass() { return cms3.ak8jets_trimmedMass(); }
	vector<float> &ak8jets_undoJEC() { return cms3.ak8jets_undoJEC(); }
	vector<float> &vtxs_chi2() { return cms3.vtxs_chi2(); }
	vector<float> &vtxs_ndof() { return cms3.vtxs_ndof(); }
	vector<float> &vtxs_sumpt() { return cms3.vtxs_sumpt(); }
	vector<float> &vtxs_xError() { return cms3.vtxs_xError(); }
	vector<float> &vtxs_yError() { return cms3.vtxs_yError(); }
	vector<float> &vtxs_zError() { return cms3.vtxs_zError(); }
	vector<vector<float> > &els_convs_dcot() { return cms3.els_convs_dcot(); }
	vector<vector<float> > &els_convs_dist() { return cms3.els_convs_dist(); }
	vector<vector<float> > &els_convs_radius() { return cms3.els_convs_radius(); }
	vector<vector<float> > &mus_stationShowerDeltaR() { return cms3.mus_stationShowerDeltaR(); }
	vector<vector<float> > &mus_stationShowerSizeT() { return cms3.mus_stationShowerSizeT(); }
	vector<vector<float> > &puInfo_instLumi() { return cms3.puInfo_instLumi(); }
	vector<vector<float> > &vtxs_covMatrix() { return cms3.vtxs_covMatrix(); }
	int &evt_bsType() { return cms3.evt_bsType(); }
	int &evt_bunchCrossing() { return cms3.evt_bunchCrossing(); }
	int &evt_experimentType() { return cms3.evt_experimentType(); }
	int &evt_isRealData() { return cms3.evt_isRealData(); }
	int &evt_orbitNumber() { return cms3.evt_orbitNumber(); }
	int &evt_storeNumber() { return cms3.evt_storeNumber(); }
	int &hcalnoise_GetRecHitCount() { return cms3.hcalnoise_GetRecHitCount(); }
	int &hcalnoise_GetRecHitCount15() { return cms3.hcalnoise_GetRecHitCount15(); }
	int &hcalnoise_maxHPDHits() { return cms3.hcalnoise_maxHPDHits(); }
	int &hcalnoise_maxHPDNoOtherHits() { return cms3.hcalnoise_maxHPDNoOtherHits(); }
	int &hcalnoise_maxRBXHits() { return cms3.hcalnoise_maxRBXHits(); }
	int &hcalnoise_maxZeros() { return cms3.hcalnoise_maxZeros(); }
	int &hcalnoise_noiseFilterStatus() { return cms3.hcalnoise_noiseFilterStatus(); }
	int &hcalnoise_noiseType() { return cms3.hcalnoise_noiseType(); }
	int &hcalnoise_num10GeVHits() { return cms3.hcalnoise_num10GeVHits(); }
	int &hcalnoise_num25GeVHits() { return cms3.hcalnoise_num25GeVHits(); }
	int &hcalnoise_numFlatNoiseChannels() { return cms3.hcalnoise_numFlatNoiseChannels(); }
	int &hcalnoise_numIsolatedNoiseChannels() { return cms3.hcalnoise_numIsolatedNoiseChannels(); }
	int &hcalnoise_numProblematicRBXs() { return cms3.hcalnoise_numProblematicRBXs(); }
	int &hcalnoise_numSpikeNoiseChannels() { return cms3.hcalnoise_numSpikeNoiseChannels(); }
	int &hcalnoise_numTS4TS5NoiseChannels() { return cms3.hcalnoise_numTS4TS5NoiseChannels(); }
	int &hcalnoise_numTriangleNoiseChannels() { return cms3.hcalnoise_numTriangleNoiseChannels(); }
	int &hcalnoise_passHighLevelNoiseFilter() { return cms3.hcalnoise_passHighLevelNoiseFilter(); }
	int &hcalnoise_passLooseNoiseFilter() { return cms3.hcalnoise_passLooseNoiseFilter(); }
	int &hcalnoise_passTightNoiseFilter() { return cms3.hcalnoise_passTightNoiseFilter(); }
	int &pdfinfo_id1() { return cms3.pdfinfo_id1(); }
	int &pdfinfo_id2() { return cms3.pdfinfo_id2(); }
	vector<int> &els_mc3_id() { return cms3.els_mc3_id(); }
	vector<int> &els_mc3idx() { return cms3.els_mc3idx(); }
	vector<int> &els_mc3_motherid() { return cms3.els_mc3_motherid(); }
	vector<int> &els_mc3_motheridx() { return cms3.els_mc3_motheridx(); }
	vector<int> &els_mc_id() { return cms3.els_mc_id(); }
	vector<int> &els_mcidx() { return cms3.els_mcidx(); }
	vector<int> &els_mc_motherid() { return cms3.els_mc_motherid(); }
	vector<int> &mus_mc3_id() { return cms3.mus_mc3_id(); }
	vector<int> &mus_mc3idx() { return cms3.mus_mc3idx(); }
	vector<int> &mus_mc3_motherid() { return cms3.mus_mc3_motherid(); }
	vector<int> &mus_mc3_motheridx() { return cms3.mus_mc3_motheridx(); }
	vector<int> &mus_mc_id() { return cms3.mus_mc_id(); }
	vector<int> &mus_mcidx() { return cms3.mus_mcidx(); }
	vector<int> &mus_mc_motherid() { return cms3.mus_mc_motherid(); }
	vector<int> &pfjets_mc3_id() { return cms3.pfjets_mc3_id(); }
	vector<int> &pfjets_mc3idx() { return cms3.pfjets_mc3idx(); }
	vector<int> &pfjets_mc_gpidx() { return cms3.pfjets_mc_gpidx(); }
	vector<int> &pfjets_mc_id() { return cms3.pfjets_mc_id(); }
	vector<int> &pfjets_mcidx() { return cms3.pfjets_mcidx(); }
	vector<int> &pfjets_mc_motherid() { return cms3.pfjets_mc_motherid(); }
	vector<int> &photons_mc3_id() { return cms3.photons_mc3_id(); }
	vector<int> &photons_mc3idx() { return cms3.photons_mc3idx(); }
	vector<int> &photons_mc3_motherid() { return cms3.photons_mc3_motherid(); }
	vector<int> &photons_mc3_motheridx() { return cms3.photons_mc3_motheridx(); }
	vector<int> &photons_mc_id() { return cms3.photons_mc_id(); }
	vector<int> &photons_mcidx() { return cms3.photons_mcidx(); }
	vector<int> &photons_mc_motherid() { return cms3.photons_mc_motherid(); }
	vector<int> &els_category() { return cms3.els_category(); }
	vector<int> &els_charge() { return cms3.els_charge(); }
	vector<int> &els_ckf_charge() { return cms3.els_ckf_charge(); }
	vector<int> &els_ckf_laywithmeas() { return cms3.els_ckf_laywithmeas(); }
	vector<int> &els_class() { return cms3.els_class(); }
	vector<int> &els_conv_delMissHits() { return cms3.els_conv_delMissHits(); }
	vector<int> &els_conv_flag() { return cms3.els_conv_flag(); }
	vector<int> &els_conv_gsftkidx() { return cms3.els_conv_gsftkidx(); }
	vector<int> &els_conv_old_delMissHits() { return cms3.els_conv_old_delMissHits(); }
	vector<int> &els_conv_old_flag() { return cms3.els_conv_old_flag(); }
	vector<int> &els_conv_old_gsftkidx() { return cms3.els_conv_old_gsftkidx(); }
	vector<int> &els_conv_old_tkidx() { return cms3.els_conv_old_tkidx(); }
	vector<int> &els_conv_tkidx() { return cms3.els_conv_tkidx(); }
	vector<int> &els_exp_innerlayers() { return cms3.els_exp_innerlayers(); }
	vector<int> &els_exp_outerlayers() { return cms3.els_exp_outerlayers(); }
	vector<int> &els_fiduciality() { return cms3.els_fiduciality(); }
	vector<int> &els_gsftrkidx() { return cms3.els_gsftrkidx(); }
	vector<int> &els_layer1_det() { return cms3.els_layer1_det(); }
	vector<int> &els_layer1_layer() { return cms3.els_layer1_layer(); }
	vector<int> &els_layer1_sizerphi() { return cms3.els_layer1_sizerphi(); }
	vector<int> &els_layer1_sizerz() { return cms3.els_layer1_sizerz(); }
	vector<int> &els_lostHits() { return cms3.els_lostHits(); }
	vector<int> &els_lost_pixelhits() { return cms3.els_lost_pixelhits(); }
	vector<int> &els_mc_patMatch_id() { return cms3.els_mc_patMatch_id(); }
	vector<int> &els_nSeed() { return cms3.els_nSeed(); }
	vector<int> &els_nlayers() { return cms3.els_nlayers(); }
	vector<int> &els_nlayers3D() { return cms3.els_nlayers3D(); }
	vector<int> &els_nlayersLost() { return cms3.els_nlayersLost(); }
	vector<int> &els_sccharge() { return cms3.els_sccharge(); }
	vector<int> &els_scindex() { return cms3.els_scindex(); }
	vector<int> &els_trk_charge() { return cms3.els_trk_charge(); }
	vector<int> &els_trkidx() { return cms3.els_trkidx(); }
	vector<int> &els_type() { return cms3.els_type(); }
	vector<int> &els_validHits() { return cms3.els_validHits(); }
	vector<int> &els_valid_pixelhits() { return cms3.els_valid_pixelhits(); }
	vector<int> &passLooseId() { return cms3.passLooseId(); }
	vector<int> &passMediumId() { return cms3.passMediumId(); }
	vector<int> &passTightId() { return cms3.passTightId(); }
	vector<int> &passVetoId() { return cms3.passVetoId(); }
	vector<int> &genps_id() { return cms3.genps_id(); }
	vector<int> &genps_id_mother() { return cms3.genps_id_mother(); }
	vector<int> &genps_id_simplegrandma() { return cms3.genps_id_simplegrandma(); }
	vector<int> &genps_id_simplemother() { return cms3.genps_id_simplemother(); }
	vector<int> &genps_idx_mother() { return cms3.genps_idx_mother(); }
	vector<int> &genps_idx_simplemother() { return cms3.genps_idx_simplemother(); }
	vector<int> &genps_status() { return cms3.genps_status(); }
	vector<int> &hyp_ll_charge() { return cms3.hyp_ll_charge(); }
	vector<int> &hyp_ll_id() { return cms3.hyp_ll_id(); }
	vector<int> &hyp_ll_index() { return cms3.hyp_ll_index(); }
	vector<int> &hyp_lt_charge() { return cms3.hyp_lt_charge(); }
	vector<int> &hyp_lt_id() { return cms3.hyp_lt_id(); }
	vector<int> &hyp_lt_index() { return cms3.hyp_lt_index(); }
	vector<int> &hyp_type() { return cms3.hyp_type(); }
	vector<int> &mus_algo() { return cms3.mus_algo(); }
	vector<int> &mus_charge() { return cms3.mus_charge(); }
	vector<int> &mus_ecal_rawId() { return cms3.mus_ecal_rawId(); }
	vector<int> &mus_exp_innerlayers() { return cms3.mus_exp_innerlayers(); }
	vector<int> &mus_exp_outerlayers() { return cms3.mus_exp_outerlayers(); }
	vector<int> &mus_gfit_algo() { return cms3.mus_gfit_algo(); }
	vector<int> &mus_gfit_etaErr() { return cms3.mus_gfit_etaErr(); }
	vector<int> &mus_gfit_exp_innerlayer() { return cms3.mus_gfit_exp_innerlayer(); }
	vector<int> &mus_gfit_exp_outerlayer() { return cms3.mus_gfit_exp_outerlayer(); }
	vector<int> &mus_gfit_lostHits() { return cms3.mus_gfit_lostHits(); }
	vector<int> &mus_gfit_lostPixelHits() { return cms3.mus_gfit_lostPixelHits(); }
	vector<int> &mus_gfit_nlayers() { return cms3.mus_gfit_nlayers(); }
	vector<int> &mus_gfit_nlayers3D() { return cms3.mus_gfit_nlayers3D(); }
	vector<int> &mus_gfit_nlayersLost() { return cms3.mus_gfit_nlayersLost(); }
	vector<int> &mus_gfit_phiErr() { return cms3.mus_gfit_phiErr(); }
	vector<int> &mus_gfit_ptErr() { return cms3.mus_gfit_ptErr(); }
	vector<int> &mus_gfit_qualityMask() { return cms3.mus_gfit_qualityMask(); }
	vector<int> &mus_gfit_trk_charge() { return cms3.mus_gfit_trk_charge(); }
	vector<int> &mus_gfit_validHits() { return cms3.mus_gfit_validHits(); }
	vector<int> &mus_gfit_validPixelHits() { return cms3.mus_gfit_validPixelHits(); }
	vector<int> &mus_gfit_validSTAHits() { return cms3.mus_gfit_validSTAHits(); }
	vector<int> &mus_gfit_validSiHits() { return cms3.mus_gfit_validSiHits(); }
	vector<int> &mus_goodmask() { return cms3.mus_goodmask(); }
	vector<int> &mus_hcal_rawId() { return cms3.mus_hcal_rawId(); }
	vector<int> &mus_iso03_njets() { return cms3.mus_iso03_njets(); }
	vector<int> &mus_iso03_ntrk() { return cms3.mus_iso03_ntrk(); }
	vector<int> &mus_iso05_ntrk() { return cms3.mus_iso05_ntrk(); }
	vector<int> &mus_lostHits() { return cms3.mus_lostHits(); }
	vector<int> &mus_lostPixelHits() { return cms3.mus_lostPixelHits(); }
	vector<int> &mus_mc_patMatch_id() { return cms3.mus_mc_patMatch_id(); }
	vector<int> &mus_muonBestTrackType() { return cms3.mus_muonBestTrackType(); }
	vector<int> &mus_nOverlaps() { return cms3.mus_nOverlaps(); }
	vector<int> &mus_nlayers() { return cms3.mus_nlayers(); }
	vector<int> &mus_nlayers3D() { return cms3.mus_nlayers3D(); }
	vector<int> &mus_nlayersLost() { return cms3.mus_nlayersLost(); }
	vector<int> &mus_nmatches() { return cms3.mus_nmatches(); }
	vector<int> &mus_numberOfMatchedStations() { return cms3.mus_numberOfMatchedStations(); }
	vector<int> &mus_overlap0() { return cms3.mus_overlap0(); }
	vector<int> &mus_overlap1() { return cms3.mus_overlap1(); }
	vector<int> &mus_pfcharge() { return cms3.mus_pfcharge(); }
	vector<int> &mus_pfidx() { return cms3.mus_pfidx(); }
	vector<int> &mus_pfparticleId() { return cms3.mus_pfparticleId(); }
	vector<int> &mus_pid_PFMuon() { return cms3.mus_pid_PFMuon(); }
	vector<int> &mus_pid_TM2DCompatibilityLoose() { return cms3.mus_pid_TM2DCompatibilityLoose(); }
	vector<int> &mus_pid_TM2DCompatibilityTight() { return cms3.mus_pid_TM2DCompatibilityTight(); }
	vector<int> &mus_pid_TMLastStationLoose() { return cms3.mus_pid_TMLastStationLoose(); }
	vector<int> &mus_pid_TMLastStationTight() { return cms3.mus_pid_TMLastStationTight(); }
	vector<int> &mus_qualityMask() { return cms3.mus_qualityMask(); }
	vector<int> &mus_sta_algo() { return cms3.mus_sta_algo(); }
	vector<int> &mus_sta_etaErr() { return cms3.mus_sta_etaErr(); }
	vector<int> &mus_sta_exp_innerlayer() { return cms3.mus_sta_exp_innerlayer(); }
	vector<int> &mus_sta_exp_outerlayer() { return cms3.mus_sta_exp_outerlayer(); }
	vector<int> &mus_sta_lostHits() { return cms3.mus_sta_lostHits(); }
	vector<int> &mus_sta_lostPixelHits() { return cms3.mus_sta_lostPixelHits(); }
	vector<int> &mus_sta_nlayers() { return cms3.mus_sta_nlayers(); }
	vector<int> &mus_sta_nlayers3D() { return cms3.mus_sta_nlayers3D(); }
	vector<int> &mus_sta_nlayersLost() { return cms3.mus_sta_nlayersLost(); }
	vector<int> &mus_sta_phiErr() { return cms3.mus_sta_phiErr(); }
	vector<int> &mus_sta_ptErr() { return cms3.mus_sta_ptErr(); }
	vector<int> &mus_sta_qualityMask() { return cms3.mus_sta_qualityMask(); }
	vector<int> &mus_sta_trk_charge() { return cms3.mus_sta_trk_charge(); }
	vector<int> &mus_sta_validHits() { return cms3.mus_sta_validHits(); }
	vector<int> &mus_sta_validPixelHits() { return cms3.mus_sta_validPixelHits(); }
	vector<int> &mus_timeDirection() { return cms3.mus_timeDirection(); }
	vector<int> &mus_timeNumStationsUsed() { return cms3.mus_timeNumStationsUsed(); }
	vector<int> &mus_trk_charge() { return cms3.mus_trk_charge(); }
	vector<int> &mus_trkidx() { return cms3.mus_trkidx(); }
	vector<int> &mus_type() { return cms3.mus_type(); }
	vector<int> &mus_validHits() { return cms3.mus_validHits(); }
	vector<int> &mus_validPixelHits() { return cms3.mus_validPixelHits(); }
	vector<int> &pfcands_charge() { return cms3.pfcands_charge(); }
	vector<int> &pfcands_particleId() { return cms3.pfcands_particleId(); }
	vector<int> &pfjets_chargedHadronMultiplicity() { return cms3.pfjets_chargedHadronMultiplicity(); }
	vector<int> &pfjets_chargedMultiplicity() { return cms3.pfjets_chargedMultiplicity(); }
	vector<int> &pfjets_electronMultiplicity() { return cms3.pfjets_electronMultiplicity(); }
	vector<int> &pfjets_hfEmMultiplicity() { return cms3.pfjets_hfEmMultiplicity(); }
	vector<int> &pfjets_hfHadronMultiplicity() { return cms3.pfjets_hfHadronMultiplicity(); }
	vector<int> &pfjets_muonMultiplicity() { return cms3.pfjets_muonMultiplicity(); }
	vector<int> &pfjets_neutralHadronMultiplicity() { return cms3.pfjets_neutralHadronMultiplicity(); }
	vector<int> &pfjets_neutralMultiplicity() { return cms3.pfjets_neutralMultiplicity(); }
	vector<int> &pfjets_partonFlavour() { return cms3.pfjets_partonFlavour(); }
	vector<int> &pfjets_photonMultiplicity() { return cms3.pfjets_photonMultiplicity(); }
	vector<int> &taus_pf_charge() { return cms3.taus_pf_charge(); }
	vector<int> &photons_fiduciality() { return cms3.photons_fiduciality(); }
	vector<int> &photons_photonID_loose() { return cms3.photons_photonID_loose(); }
	vector<int> &photons_photonID_tight() { return cms3.photons_photonID_tight(); }
	vector<int> &puInfo_bunchCrossing() { return cms3.puInfo_bunchCrossing(); }
	vector<int> &puInfo_nPUvertices() { return cms3.puInfo_nPUvertices(); }
	vector<int> &convs_algo() { return cms3.convs_algo(); }
	vector<int> &convs_isConverted() { return cms3.convs_isConverted(); }
	vector<int> &convs_quality() { return cms3.convs_quality(); }
	vector<int> &svs_nTrks() { return cms3.svs_nTrks(); }
	vector<int> &ak8jets_chargedHadronMultiplicity() { return cms3.ak8jets_chargedHadronMultiplicity(); }
	vector<int> &ak8jets_chargedMultiplicity() { return cms3.ak8jets_chargedMultiplicity(); }
	vector<int> &ak8jets_electronMultiplicity() { return cms3.ak8jets_electronMultiplicity(); }
	vector<int> &ak8jets_hfEmMultiplicity() { return cms3.ak8jets_hfEmMultiplicity(); }
	vector<int> &ak8jets_hfHadronMultiplicity() { return cms3.ak8jets_hfHadronMultiplicity(); }
	vector<int> &ak8jets_muonMultiplicity() { return cms3.ak8jets_muonMultiplicity(); }
	vector<int> &ak8jets_neutralHadronMultiplicity() { return cms3.ak8jets_neutralHadronMultiplicity(); }
	vector<int> &ak8jets_neutralMultiplicity() { return cms3.ak8jets_neutralMultiplicity(); }
	vector<int> &ak8jets_partonFlavour() { return cms3.ak8jets_partonFlavour(); }
	vector<int> &ak8jets_photonMultiplicity() { return cms3.ak8jets_photonMultiplicity(); }
	vector<int> &vtxs_isFake() { return cms3.vtxs_isFake(); }
	vector<int> &vtxs_isValid() { return cms3.vtxs_isValid(); }
	vector<int> &vtxs_tracksSize() { return cms3.vtxs_tracksSize(); }
	vector<vector<int> > &els_convs_delMissHits() { return cms3.els_convs_delMissHits(); }
	vector<vector<int> > &els_convs_flag() { return cms3.els_convs_flag(); }
	vector<vector<int> > &els_convs_gsftkidx() { return cms3.els_convs_gsftkidx(); }
	vector<vector<int> > &els_convs_tkidx() { return cms3.els_convs_tkidx(); }
	vector<vector<int> > &els_PFCand_idx() { return cms3.els_PFCand_idx(); }
	vector<vector<int> > &genps_lepdaughter_id() { return cms3.genps_lepdaughter_id(); }
	vector<vector<int> > &genps_lepdaughter_idx() { return cms3.genps_lepdaughter_idx(); }
	vector<vector<int> > &hlt_trigObjs_id() { return cms3.hlt_trigObjs_id(); }
	vector<vector<int> > &mus_nStationCorrelatedHits() { return cms3.mus_nStationCorrelatedHits(); }
	vector<vector<int> > &mus_nStationHits() { return cms3.mus_nStationHits(); }
	vector<vector<int> > &pfjets_pfcandIndicies() { return cms3.pfjets_pfcandIndicies(); }
	vector<vector<int> > &photons_PFCand_idx() { return cms3.photons_PFCand_idx(); }
	vector<vector<int> > &convs_nHitsBeforeVtx() { return cms3.convs_nHitsBeforeVtx(); }
	vector<vector<int> > &convs_tkalgo() { return cms3.convs_tkalgo(); }
	vector<vector<int> > &convs_tkidx() { return cms3.convs_tkidx(); }
	vector<vector<int> > &ak8jets_pfcandIndicies() { return cms3.ak8jets_pfcandIndicies(); }
	vector<unsigned char> &pfcands_fromPV() { return cms3.pfcands_fromPV(); }
	unsigned int &els_HLT_Ele17_Ele8_L1sL1DoubleEG137_version() { return cms3.els_HLT_Ele17_Ele8_L1sL1DoubleEG137_version(); }
	unsigned int &els_HLT_Ele17_Ele8_LeadingLeg_version() { return cms3.els_HLT_Ele17_Ele8_LeadingLeg_version(); }
	unsigned int &els_HLT_Ele17_Ele8_Mass50_LeadingLeg_version() { return cms3.els_HLT_Ele17_Ele8_Mass50_LeadingLeg_version(); }
	unsigned int &els_HLT_Ele17_Ele8_Mass50_TrailingLeg_version() { return cms3.els_HLT_Ele17_Ele8_Mass50_TrailingLeg_version(); }
	unsigned int &els_HLT_Ele17_Ele8_TrailingLeg_version() { return cms3.els_HLT_Ele17_Ele8_TrailingLeg_version(); }
	unsigned int &els_HLT_Ele17_Ele8_version() { return cms3.els_HLT_Ele17_Ele8_version(); }
	unsigned int &els_HLT_Ele20_SC4_Mass50_LeadingLeg_version() { return cms3.els_HLT_Ele20_SC4_Mass50_LeadingLeg_version(); }
	unsigned int &els_HLT_Ele20_SC4_Mass50_TrailingLeg_version() { return cms3.els_HLT_Ele20_SC4_Mass50_TrailingLeg_version(); }
	unsigned int &els_HLT_Ele27_WP80_L1sL1SingleEG20ORL1SingleEG22_version() { return cms3.els_HLT_Ele27_WP80_L1sL1SingleEG20ORL1SingleEG22_version(); }
	unsigned int &els_HLT_Ele27_WP80_version() { return cms3.els_HLT_Ele27_WP80_version(); }
	unsigned int &els_HLT_Ele32_SC17_Mass50_LeadingLeg_version() { return cms3.els_HLT_Ele32_SC17_Mass50_LeadingLeg_version(); }
	unsigned int &els_HLT_Ele32_SC17_Mass50_TrailingLeg_version() { return cms3.els_HLT_Ele32_SC17_Mass50_TrailingLeg_version(); }
	unsigned int &els_HLT_Mu17_Ele8_TrailingLeg_version() { return cms3.els_HLT_Mu17_Ele8_TrailingLeg_version(); }
	unsigned int &els_HLT_Mu17_Ele8_version() { return cms3.els_HLT_Mu17_Ele8_version(); }
	unsigned int &els_HLT_Mu8_Ele17_version() { return cms3.els_HLT_Mu8_Ele17_version(); }
	unsigned int &evt_nels() { return cms3.evt_nels(); }
	unsigned int &evt_detectorStatus() { return cms3.evt_detectorStatus(); }
	unsigned int &evt_event() { return cms3.evt_event(); }
	unsigned int &evt_lumiBlock() { return cms3.evt_lumiBlock(); }
	unsigned int &evt_run() { return cms3.evt_run(); }
	unsigned int &evt_ngenjetsNoMuNoNu() { return cms3.evt_ngenjetsNoMuNoNu(); }
	unsigned int &genps_signalProcessID() { return cms3.genps_signalProcessID(); }
	unsigned int &mus_HLT_IsoMu24_eta2p1_L1sMu16Eta2p1_version() { return cms3.mus_HLT_IsoMu24_eta2p1_L1sMu16Eta2p1_version(); }
	unsigned int &mus_HLT_IsoMu24_eta2p1_version() { return cms3.mus_HLT_IsoMu24_eta2p1_version(); }
	unsigned int &mus_HLT_Mu17_Ele8_LeadingLeg_version() { return cms3.mus_HLT_Mu17_Ele8_LeadingLeg_version(); }
	unsigned int &mus_HLT_Mu17_Ele8_version() { return cms3.mus_HLT_Mu17_Ele8_version(); }
	unsigned int &mus_HLT_Mu17_Mu8_L1sL1DoubleMu10MuOpen_version() { return cms3.mus_HLT_Mu17_Mu8_L1sL1DoubleMu10MuOpen_version(); }
	unsigned int &mus_HLT_Mu17_Mu8_LeadingLeg_version() { return cms3.mus_HLT_Mu17_Mu8_LeadingLeg_version(); }
	unsigned int &mus_HLT_Mu17_Mu8_TrailingLeg_version() { return cms3.mus_HLT_Mu17_Mu8_TrailingLeg_version(); }
	unsigned int &mus_HLT_Mu17_Mu8_version() { return cms3.mus_HLT_Mu17_Mu8_version(); }
	unsigned int &mus_HLT_Mu17_TkMu8_LeadingLeg_version() { return cms3.mus_HLT_Mu17_TkMu8_LeadingLeg_version(); }
	unsigned int &mus_HLT_Mu17_TkMu8_TrailingLegTrkFiltered_version() { return cms3.mus_HLT_Mu17_TkMu8_TrailingLegTrkFiltered_version(); }
	unsigned int &mus_HLT_Mu17_TkMu8_TrailingLeg_version() { return cms3.mus_HLT_Mu17_TkMu8_TrailingLeg_version(); }
	unsigned int &mus_HLT_Mu17_TkMu8_version() { return cms3.mus_HLT_Mu17_TkMu8_version(); }
	unsigned int &mus_HLT_Mu8_Ele17_TrailingLeg_version() { return cms3.mus_HLT_Mu8_Ele17_TrailingLeg_version(); }
	unsigned int &mus_HLT_Mu8_Ele17_version() { return cms3.mus_HLT_Mu8_Ele17_version(); }
	unsigned int &evt_nphotons() { return cms3.evt_nphotons(); }
	unsigned int &evt_nvtxs() { return cms3.evt_nvtxs(); }
	vector<unsigned int> &els_HLT_Ele17_Ele8() { return cms3.els_HLT_Ele17_Ele8(); }
	vector<unsigned int> &els_HLT_Ele17_Ele8_L1sL1DoubleEG137() { return cms3.els_HLT_Ele17_Ele8_L1sL1DoubleEG137(); }
	vector<unsigned int> &els_HLT_Ele17_Ele8_LeadingLeg() { return cms3.els_HLT_Ele17_Ele8_LeadingLeg(); }
	vector<unsigned int> &els_HLT_Ele17_Ele8_Mass50_LeadingLeg() { return cms3.els_HLT_Ele17_Ele8_Mass50_LeadingLeg(); }
	vector<unsigned int> &els_HLT_Ele17_Ele8_Mass50_TrailingLeg() { return cms3.els_HLT_Ele17_Ele8_Mass50_TrailingLeg(); }
	vector<unsigned int> &els_HLT_Ele17_Ele8_TrailingLeg() { return cms3.els_HLT_Ele17_Ele8_TrailingLeg(); }
	vector<unsigned int> &els_HLT_Ele20_SC4_Mass50_LeadingLeg() { return cms3.els_HLT_Ele20_SC4_Mass50_LeadingLeg(); }
	vector<unsigned int> &els_HLT_Ele20_SC4_Mass50_TrailingLeg() { return cms3.els_HLT_Ele20_SC4_Mass50_TrailingLeg(); }
	vector<unsigned int> &els_HLT_Ele27_WP80() { return cms3.els_HLT_Ele27_WP80(); }
	vector<unsigned int> &els_HLT_Ele27_WP80_L1sL1SingleEG20ORL1SingleEG22() { return cms3.els_HLT_Ele27_WP80_L1sL1SingleEG20ORL1SingleEG22(); }
	vector<unsigned int> &els_HLT_Ele32_SC17_Mass50_LeadingLeg() { return cms3.els_HLT_Ele32_SC17_Mass50_LeadingLeg(); }
	vector<unsigned int> &els_HLT_Ele32_SC17_Mass50_TrailingLeg() { return cms3.els_HLT_Ele32_SC17_Mass50_TrailingLeg(); }
	vector<unsigned int> &els_HLT_Mu17_Ele8() { return cms3.els_HLT_Mu17_Ele8(); }
	vector<unsigned int> &els_HLT_Mu17_Ele8_TrailingLeg() { return cms3.els_HLT_Mu17_Ele8_TrailingLeg(); }
	vector<unsigned int> &els_HLT_Mu8_Ele17() { return cms3.els_HLT_Mu8_Ele17(); }
	vector<unsigned int> &hlt_prescales() { return cms3.hlt_prescales(); }
	vector<unsigned int> &mus_HLT_IsoMu24_eta2p1() { return cms3.mus_HLT_IsoMu24_eta2p1(); }
	vector<unsigned int> &mus_HLT_IsoMu24_eta2p1_L1sMu16Eta2p1() { return cms3.mus_HLT_IsoMu24_eta2p1_L1sMu16Eta2p1(); }
	vector<unsigned int> &mus_HLT_Mu17_Ele8() { return cms3.mus_HLT_Mu17_Ele8(); }
	vector<unsigned int> &mus_HLT_Mu17_Ele8_LeadingLeg() { return cms3.mus_HLT_Mu17_Ele8_LeadingLeg(); }
	vector<unsigned int> &mus_HLT_Mu17_Mu8() { return cms3.mus_HLT_Mu17_Mu8(); }
	vector<unsigned int> &mus_HLT_Mu17_Mu8_L1sL1DoubleMu10MuOpen() { return cms3.mus_HLT_Mu17_Mu8_L1sL1DoubleMu10MuOpen(); }
	vector<unsigned int> &mus_HLT_Mu17_Mu8_LeadingLeg() { return cms3.mus_HLT_Mu17_Mu8_LeadingLeg(); }
	vector<unsigned int> &mus_HLT_Mu17_Mu8_TrailingLeg() { return cms3.mus_HLT_Mu17_Mu8_TrailingLeg(); }
	vector<unsigned int> &mus_HLT_Mu17_TkMu8() { return cms3.mus_HLT_Mu17_TkMu8(); }
	vector<unsigned int> &mus_HLT_Mu17_TkMu8_LeadingLeg() { return cms3.mus_HLT_Mu17_TkMu8_LeadingLeg(); }
	vector<unsigned int> &mus_HLT_Mu17_TkMu8_TrailingLeg() { return cms3.mus_HLT_Mu17_TkMu8_TrailingLeg(); }
	vector<unsigned int> &mus_HLT_Mu17_TkMu8_TrailingLegTrkFiltered() { return cms3.mus_HLT_Mu17_TkMu8_TrailingLegTrkFiltered(); }
	vector<unsigned int> &mus_HLT_Mu8_Ele17() { return cms3.mus_HLT_Mu8_Ele17(); }
	vector<unsigned int> &mus_HLT_Mu8_Ele17_TrailingLeg() { return cms3.mus_HLT_Mu8_Ele17_TrailingLeg(); }
	int &evt_nEvts() { return cms3.evt_nEvts(); }
	float &evt_filt_eff() { return cms3.evt_filt_eff(); }
	bool passHLTTrigger(TString trigName) { return cms3.passHLTTrigger(trigName); }
}
