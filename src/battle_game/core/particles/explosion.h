#pragma once
#include "battle_game/core/particle.h"

namespace battle_game::particle {
class Explosion : public Particle {
 public:
  Explosion(GameCore *game_core,
        uint32_t id,
        glm::vec2 position,
        float rotation,
        float size = 1.0f);
  void Render() override;
  void Update() override;

 private:
  float size_{};
};
}  // namespace battle_game::particle
