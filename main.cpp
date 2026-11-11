#include <Windows.h>
#include "KamataEngine.h"
#include "GameScene.h"
#include "TitleScene.h"

using namespace KamataEngine;
TitleScene* titleScene = nullptr;
GameScene* gameScene_ = nullptr;

enum class Scene {
	kUnknown = 0,
	kTitle,
	kGame,

};

Scene scene = Scene::kTitle;



void UpdateScene() {
	switch (scene) {
	case Scene::kTitle:
		titleScene->Update();

		break;
	case Scene::kGame:
		gameScene_->Update();
		break;
	}
};

void DrawScene() {

	switch (scene) {
	case Scene::kTitle:
		titleScene->Draw();

		break;
	case Scene::kGame:
		gameScene_->Draw();
		break;
	}
}

void ChangeScene() {
	switch (scene) {
	case Scene::kTitle:
		if (titleScene->GetIsFinished()) {
			scene = Scene::kGame;
			delete titleScene;
			titleScene = nullptr;
			gameScene_ = new GameScene();
			// gameScene_->Initialize(stageManager);
		}
		break;
	case Scene::kGame:
		if (gameScene_->GetIsFinished()) {
			scene = Scene::kTitle;
			delete gameScene_;
			gameScene_ = nullptr;

			titleScene = new TitleScene;
			titleScene->Initialize();

		} else if (gameScene_->GetIsReloadRequseted()) {

			delete gameScene_;
			gameScene_ = nullptr;

			gameScene_ = new GameScene();
			// gameScene_->Initialize(stageManager);
		}

		break;
	}
};

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	
	return 0;
}
