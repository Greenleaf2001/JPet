#pragma once
#pragma once
#include <CubismFramework.hpp>
#include "Model/CubismModel.hpp"
#include "Utils/CubismJson.hpp"
#include <map>
#include <string>
#include <vector>
using std::map;
using std::string;
using std::vector;
using namespace Live2D::Cubism::Framework;

class PartStateManager
{
	vector<CubismIdHandle> ParamIdList;
	map<string, float> ParamState;
	CubismModel* model = nullptr;
public:
	const int ParamNum = 17;
	const char* ParamList[17] = {
		"ParamClothes",
		"ParamQuan",
		"ParamStar",
		"ParamVeye",
		"ParamMouth1",
		"ParamMouth2",
		"ParamMouth3",
		"ParamMouth4",
		"ParamMouth5",
		"Param",
		"ParamGun",
		"ParamHat",
		"ParamKneeSocks",
		"ParamEarl",
		"ParamEarr",
		"ParamLegBelt",
		"ParamSleeveShow"
	};
	const float ParamDefault[17] = {
		0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0
	};
	static PartStateManager* GetInstance();
	void SetModel(CubismModel* m);
	void SaveState();
	float GetState(string param);
	void SetState();
	void ImportState(map<string, float> State) { ParamState = State; }
	map<string, float> GetAllState() { return ParamState; }
};



/*
�� 20 ������
���岿�֣�
ParamClothes - �¾��·������л���0 -> 1 | �� -> ��

�۾����֣�
ParamQuan	 - ȦȦ�ۣ�0 -> 1
ParamStar	 - �����ۣ�0 -> 1
ParamVeye	 - V���ۣ�0 -> 1

�첿��
ParamMouth1  - ��Į
ParamMouth2  - �ſ�
ParamMouth3  - ������
ParamMouth4  - ����
ParamMouth5  - ����
Param		 - ����: -30 -> 30

������λ��
ParamGun     - ǹ
ParamHat     - ñ��
ParamKneeSocks - ����
ParamEarl    - ���
ParamEarr    - �Ҷ�
ParamLegBelt - �Ȼ�
ParamSleeveShow - ����
*/


