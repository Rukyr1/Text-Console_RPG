#pragma once
class AudioManager
{
public:
	AudioManager();

	void StopAudio(); //음악 끄기

	//------------BGM------------
	void OpeningBgm(); //오프닝 배경음악
	void IntroBgm(); //인트로 배경음악
	void EndingBgm(); //엔딩 배경음악
	void VillageBgm(); //마을 배경음악
	void CenterShopBgm(); //포켓몬 센터 및 상점 배경음악
	void BattleWild(); //야생 포켓몬과 대결 할 때 배경음악
	void BattleWildVictory(); //야생 포켓몬과 대결에서 승리했을 때 배경음악
	void Evolution(); //포켓몬 진화 배경음악

	//------------SFX------------
	void EnterSfx(); //엔터 누를 때 효과음
	void BulbasaurSfx(); //이상해씨 울음소리
	void CharmanderSfx(); //파이리 울음소리
	void SquirtleSfx(); //꼬부기 울음소리
	void HealSfx(); //센터에서 힐 받았을 때 효과음
	void LevelUp(); //레벨업 효과음
	void ItemReward(); //아이템 보상 얻었을 때

};

