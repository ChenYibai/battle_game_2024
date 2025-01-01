#pragma once
#include "battle_game/core/particle.h"

namespace battle_game::particle {
class Bomb : public Particle {
 public:
  Bomb(GameCore *game_core,
        uint32_t id,
        glm::vec2 position,
        float rotation,
        uint32_t explode_count_down);
  void Render() override;
  void Update() override;

 private:
  uint32_t explode_count_down_{0};
};
}  // namespace battle_game::particle
