#include "battle_game/core/particles/explosion.h"

#include "battle_game/core/game_core.h"

namespace battle_game::particle {
Explosion::Explosion(GameCore *game_core,
             uint32_t id,
             glm::vec2 position,
             float rotation,
             float size)
    : Particle(game_core, id, position, rotation),
      size_(size) {
}

void Explosion::Render() {
  SetTransformation(position_, rotation_, glm::vec2{size_});
  SetColor(glm::vec4{1.0f, 1.0f, 1.0f, 1.0f});
  DrawTexture(BATTLE_GAME_ASSETS_DIR "textures/particle4.png");
}

void Explosion::Update() {
  size_ += kSecondPerTick * 3.6f;
  if (size_ > 1.4f) {
    game_core_->PushEventRemoveParticle(id_);
  }
}
}  // namespace battle_game::particle
