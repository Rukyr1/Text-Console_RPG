#include "AudioManager.h"
#include <Windows.h> //PlaySound
// SND_ANYNC: 음악 재생 중에도 다음 코드 실행
// SND_LOOP: 무한 반복


AudioManager::AudioManager()
{
}

void AudioManager::StopAudio()
{
	mciSendString(TEXT("stop bgm"), NULL, 0, NULL);
	mciSendString(TEXT("close bgm"), NULL, 0, NULL);
}

void AudioManager::OpeningBgm()
{
	PlaySound(TEXT("music/1-01.-Opening.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void AudioManager::IntroBgm()
{
	mciSendString(TEXT("open \"music/1-03.-Professor-Oak.wav\" type mpegvideo alias bgm"), NULL, 0, NULL);
	mciSendString(TEXT("play bgm repeat"), NULL, 0, NULL);
}

void AudioManager::EndingBgm()
{
	PlaySound(TEXT("music/1-45.-_Ending_-_1_.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void AudioManager::VillageBgm()
{
	PlaySound(TEXT("music/1-06.-Road-to-Viridian-City-–-From-Pallet.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void AudioManager::CenterShopBgm()
{
	PlaySound(TEXT("music/1-10.-Pokémon-Center.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void AudioManager::BattleWild()
{
	PlaySound(TEXT("music/1-07.-Battle-_VS-Wild-Pokémon_.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void AudioManager::BattleWildVictory()
{
	PlaySound(TEXT("music/1-08.-Victory-_VS-Wild-Pokémon_.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void AudioManager::Evolution()
{
	PlaySound(TEXT("music/1-41.-Evolution.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void AudioManager::EnterSfx()
{
	PlaySound(TEXT("music/pokemon_a_button.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void AudioManager::BulbasaurSfx()
{
	mciSendString(TEXT("close sfx"), NULL, 0, NULL);
	mciSendString(TEXT("open \"music/001-bulbasaur_1.wav\" alias sfx"), NULL, 0, NULL);
	mciSendString(TEXT("play sfx"), NULL, 0, NULL);
}

void AudioManager::CharmanderSfx()
{
	mciSendString(TEXT("close sfx"), NULL, 0, NULL);
	mciSendString(TEXT("open \"music/004-charmander_1.wav\" alias sfx"), NULL, 0, NULL);
	mciSendString(TEXT("play sfx"), NULL, 0, NULL);
}

void AudioManager::SquirtleSfx()
{
	mciSendString(TEXT("close sfx"), NULL, 0, NULL);
	mciSendString(TEXT("open \"music/007-squirtle_1.wav\" alias sfx"), NULL, 0, NULL);
	mciSendString(TEXT("play sfx"), NULL, 0, NULL);
}

void AudioManager::HealSfx()
{
	PlaySound(TEXT("music/healing-pokemon-sound.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void AudioManager::LevelUp()
{
	PlaySound(TEXT("music/pokemon-red_blue_yellow-level-up-sound-effect_m91UE0V.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void AudioManager::ItemReward()
{
	PlaySound(TEXT("music/pokemon-redblueyellow-item-found-sound-effect.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
