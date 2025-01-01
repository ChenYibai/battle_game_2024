#include "battle_game/core/particles/bomb.h"
#include "battle_game/core/particles/explosion.h"

#include "battle_game/core/game_core.h"

namespace battle_game::particle {
Bomb::Bomb(GameCore *game_core,
        uint32_t id,
        glm::vec2 position,
        float rotation,
        uint32_t explode_count_down)
    : Particle(game_core, id, position, rotation),
      explode_count_down_(explode_count_down) {
}

void Bomb::Render() {
  SetTransformation(position_, rotation_, glm::vec2{1.0f});
  SetColor(glm::vec4{1.0f, 1.0f, 1.0f, 1.0f});
  DrawTexture(BATTLE_GAME_ASSETS_DIR "textures/particle5.png");
}

void Bomb::Update() {
  if (explode_count_down_ > 0) explode_count_down_--;
  if (explode_count_down_ == 0) {
    game_core_->PushEventRemoveParticle(id_);
    game_core_->PushEventGenerateParticle<particle::Explosion>(
      position_, 0, 0.2f);
    auto &units = game_core_->GetUnits();
    for (auto &unit : units) {
        glm::vec2 unit_pos = unit.second->GetPosition();
        if (glm::length(unit_pos - position_) < 1.6f) {
            game_core_->PushEventDealDamage(unit.first, 0, 60.0f);
        }
    }
  }
}
}  // namespace battle_game::particle
