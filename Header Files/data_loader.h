#pragma once
#include "classes.h"
#include <memory>
#include <vector>

std::vector<std::shared_ptr<MedicalInstitution>>loadMedicalInstitutionsFromTXT();
std::vector<std::shared_ptr<Doctor>> loadDoctorsFromTXT();
std::vector<std::shared_ptr<SupportStaff>> loadSupportStaffFromTXT();
std::vector<std::shared_ptr<Patient>> loadPatientsFromTXT();
std::vector<std::shared_ptr<Ward>> loadWardsFromTXT();
std::vector<std::shared_ptr<Bed>> loadBedsFromTXT();
std::vector<std::shared_ptr<Room>> loadRoomsFromTXT();
std::vector<std::shared_ptr<RoomVisit>> loadRoomVisitsFromTXT();
std::vector<std::shared_ptr<Operation>> loadOperationsFromTXT();
std::vector<std::shared_ptr<LabTest>> loadLabTestsFromTXT();