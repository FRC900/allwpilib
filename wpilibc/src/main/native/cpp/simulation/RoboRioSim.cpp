/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018-2020 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "frc/simulation/RoboRioSim.h"

#include <memory>
#include <utility>

#include <hal/simulation/RoboRioData.h>

using namespace frc;
using namespace frc::sim;

std::unique_ptr<CallbackStore> RoboRioSim::RegisterFPGAButtonCallback(
    NotifyCallback callback, bool initialNotify) {
  auto store = std::make_unique<CallbackStore>(
      -1, callback, &HALSIM_CancelRoboRioFPGAButtonCallback);
  store->SetUid(HALSIM_RegisterRoboRioFPGAButtonCallback(
      &CallbackStoreThunk, store.get(), initialNotify));
  return store;
}

bool RoboRioSim::GetFPGAButton() { return HALSIM_GetRoboRioFPGAButton(); }

void RoboRioSim::SetFPGAButton(bool fPGAButton) {
  HALSIM_SetRoboRioFPGAButton(fPGAButton);
}

std::unique_ptr<CallbackStore> RoboRioSim::RegisterVInVoltageCallback(
    NotifyCallback callback, bool initialNotify) {
  auto store = std::make_unique<CallbackStore>(
      -1, callback, &HALSIM_CancelRoboRioVInVoltageCallback);
  store->SetUid(HALSIM_RegisterRoboRioVInVoltageCallback(
      &CallbackStoreThunk, store.get(), initialNotify));
  return store;
}

double RoboRioSim::GetVInVoltage() { return HALSIM_GetRoboRioVInVoltage(); }

void RoboRioSim::SetVInVoltage(double vInVoltage) {
  HALSIM_SetRoboRioVInVoltage(vInVoltage);
}

std::unique_ptr<CallbackStore> RoboRioSim::RegisterVInCurrentCallback(
    NotifyCallback callback, bool initialNotify) {
  auto store = std::make_unique<CallbackStore>(
      -1, callback, &HALSIM_CancelRoboRioVInCurrentCallback);
  store->SetUid(HALSIM_RegisterRoboRioVInCurrentCallback(
      &CallbackStoreThunk, store.get(), initialNotify));
  return store;
}

double RoboRioSim::GetVInCurrent() { return HALSIM_GetRoboRioVInCurrent(); }

void RoboRioSim::SetVInCurrent(double vInCurrent) {
  HALSIM_SetRoboRioVInCurrent(vInCurrent);
}

std::unique_ptr<CallbackStore> RoboRioSim::RegisterUserVoltage6VCallback(
    NotifyCallback callback, bool initialNotify) {
  auto store = std::make_unique<CallbackStore>(
      -1, callback, &HALSIM_CancelRoboRioUserVoltage6VCallback);
  store->SetUid(HALSIM_RegisterRoboRioUserVoltage6VCallback(
      &CallbackStoreThunk, store.get(), initialNotify));
  return store;
}

double RoboRioSim::GetUserVoltage6V() {
  return HALSIM_GetRoboRioUserVoltage6V();
}

void RoboRioSim::SetUserVoltage6V(double userVoltage6V) {
  HALSIM_SetRoboRioUserVoltage6V(userVoltage6V);
}

std::unique_ptr<CallbackStore> RoboRioSim::RegisterUserCurrent6VCallback(
    NotifyCallback callback, bool initialNotify) {
  auto store = std::make_unique<CallbackStore>(
      -1, callback, &HALSIM_CancelRoboRioUserCurrent6VCallback);
  store->SetUid(HALSIM_RegisterRoboRioUserCurrent6VCallback(
      &CallbackStoreThunk, store.get(), initialNotify));
  return store;
}

double RoboRioSim::GetUserCurrent6V() {
  return HALSIM_GetRoboRioUserCurrent6V();
}

void RoboRioSim::SetUserCurrent6V(double userCurrent6V) {
  HALSIM_SetRoboRioUserCurrent6V(userCurrent6V);
}

std::unique_ptr<CallbackStore> RoboRioSim::RegisterUserActive6VCallback(
    NotifyCallback callback, bool initialNotify) {
  auto store = std::make_unique<CallbackStore>(
      -1, callback, &HALSIM_CancelRoboRioUserActive6VCallback);
  store->SetUid(HALSIM_RegisterRoboRioUserActive6VCallback(
      &CallbackStoreThunk, store.get(), initialNotify));
  return store;
}

bool RoboRioSim::GetUserActive6V() { return HALSIM_GetRoboRioUserActive6V(); }

void RoboRioSim::SetUserActive6V(bool userActive6V) {
  HALSIM_SetRoboRioUserActive6V(userActive6V);
}

std::unique_ptr<CallbackStore> RoboRioSim::RegisterUserVoltage5VCallback(
    NotifyCallback callback, bool initialNotify) {
  auto store = std::make_unique<CallbackStore>(
      -1, callback, &HALSIM_CancelRoboRioUserVoltage5VCallback);
  store->SetUid(HALSIM_RegisterRoboRioUserVoltage5VCallback(
      &CallbackStoreThunk, store.get(), initialNotify));
  return store;
}

double RoboRioSim::GetUserVoltage5V() {
  return HALSIM_GetRoboRioUserVoltage5V();
}

void RoboRioSim::SetUserVoltage5V(double userVoltage5V) {
  HALSIM_SetRoboRioUserVoltage5V(userVoltage5V);
}

std::unique_ptr<CallbackStore> RoboRioSim::RegisterUserCurrent5VCallback(
    NotifyCallback callback, bool initialNotify) {
  auto store = std::make_unique<CallbackStore>(
      -1, callback, &HALSIM_CancelRoboRioUserCurrent5VCallback);
  store->SetUid(HALSIM_RegisterRoboRioUserCurrent5VCallback(
      &CallbackStoreThunk, store.get(), initialNotify));
  return store;
}

double RoboRioSim::GetUserCurrent5V() {
  return HALSIM_GetRoboRioUserCurrent5V();
}

void RoboRioSim::SetUserCurrent5V(double userCurrent5V) {
  HALSIM_SetRoboRioUserCurrent5V(userCurrent5V);
}

std::unique_ptr<CallbackStore> RoboRioSim::RegisterUserActive5VCallback(
    NotifyCallback callback, bool initialNotify) {
  auto store = std::make_unique<CallbackStore>(
      -1, callback, &HALSIM_CancelRoboRioUserActive5VCallback);
  store->SetUid(HALSIM_RegisterRoboRioUserActive5VCallback(
      &CallbackStoreThunk, store.get(), initialNotify));
  return store;
}

bool RoboRioSim::GetUserActive5V() { return HALSIM_GetRoboRioUserActive5V(); }

void RoboRioSim::SetUserActive5V(bool userActive5V) {
  HALSIM_SetRoboRioUserActive5V(userActive5V);
}

std::unique_ptr<CallbackStore> RoboRioSim::RegisterUserVoltage3V3Callback(
    NotifyCallback callback, bool initialNotify) {
  auto store = std::make_unique<CallbackStore>(
      -1, callback, &HALSIM_CancelRoboRioUserVoltage3V3Callback);
  store->SetUid(HALSIM_RegisterRoboRioUserVoltage3V3Callback(
      &CallbackStoreThunk, store.get(), initialNotify));
  return store;
}

double RoboRioSim::GetUserVoltage3V3() {
  return HALSIM_GetRoboRioUserVoltage3V3();
}

void RoboRioSim::SetUserVoltage3V3(double userVoltage3V3) {
  HALSIM_SetRoboRioUserVoltage3V3(userVoltage3V3);
}

std::unique_ptr<CallbackStore> RoboRioSim::RegisterUserCurrent3V3Callback(
    NotifyCallback callback, bool initialNotify) {
  auto store = std::make_unique<CallbackStore>(
      -1, callback, &HALSIM_CancelRoboRioUserCurrent3V3Callback);
  store->SetUid(HALSIM_RegisterRoboRioUserCurrent3V3Callback(
      &CallbackStoreThunk, store.get(), initialNotify));
  return store;
}

double RoboRioSim::GetUserCurrent3V3() {
  return HALSIM_GetRoboRioUserCurrent3V3();
}

void RoboRioSim::SetUserCurrent3V3(double userCurrent3V3) {
  HALSIM_SetRoboRioUserCurrent3V3(userCurrent3V3);
}

std::unique_ptr<CallbackStore> RoboRioSim::RegisterUserActive3V3Callback(
    NotifyCallback callback, bool initialNotify) {
  auto store = std::make_unique<CallbackStore>(
      -1, callback, &HALSIM_CancelRoboRioUserActive3V3Callback);
  store->SetUid(HALSIM_RegisterRoboRioUserActive3V3Callback(
      &CallbackStoreThunk, store.get(), initialNotify));
  return store;
}

bool RoboRioSim::GetUserActive3V3() { return HALSIM_GetRoboRioUserActive3V3(); }

void RoboRioSim::SetUserActive3V3(bool userActive3V3) {
  HALSIM_SetRoboRioUserActive3V3(userActive3V3);
}

std::unique_ptr<CallbackStore> RoboRioSim::RegisterUserFaults6VCallback(
    NotifyCallback callback, bool initialNotify) {
  auto store = std::make_unique<CallbackStore>(
      -1, callback, &HALSIM_CancelRoboRioUserFaults6VCallback);
  store->SetUid(HALSIM_RegisterRoboRioUserFaults6VCallback(
      &CallbackStoreThunk, store.get(), initialNotify));
  return store;
}

int RoboRioSim::GetUserFaults6V() { return HALSIM_GetRoboRioUserFaults6V(); }

void RoboRioSim::SetUserFaults6V(int userFaults6V) {
  HALSIM_SetRoboRioUserFaults6V(userFaults6V);
}

std::unique_ptr<CallbackStore> RoboRioSim::RegisterUserFaults5VCallback(
    NotifyCallback callback, bool initialNotify) {
  auto store = std::make_unique<CallbackStore>(
      -1, callback, &HALSIM_CancelRoboRioUserFaults5VCallback);
  store->SetUid(HALSIM_RegisterRoboRioUserFaults5VCallback(
      &CallbackStoreThunk, store.get(), initialNotify));
  return store;
}

int RoboRioSim::GetUserFaults5V() { return HALSIM_GetRoboRioUserFaults5V(); }

void RoboRioSim::SetUserFaults5V(int userFaults5V) {
  HALSIM_SetRoboRioUserFaults5V(userFaults5V);
}

std::unique_ptr<CallbackStore> RoboRioSim::RegisterUserFaults3V3Callback(
    NotifyCallback callback, bool initialNotify) {
  auto store = std::make_unique<CallbackStore>(
      -1, callback, &HALSIM_CancelRoboRioUserFaults3V3Callback);
  store->SetUid(HALSIM_RegisterRoboRioUserFaults3V3Callback(
      &CallbackStoreThunk, store.get(), initialNotify));
  return store;
}

int RoboRioSim::GetUserFaults3V3() { return HALSIM_GetRoboRioUserFaults3V3(); }

void RoboRioSim::SetUserFaults3V3(int userFaults3V3) {
  HALSIM_SetRoboRioUserFaults3V3(userFaults3V3);
}

void ResetData() { HALSIM_ResetRoboRioData(); }
