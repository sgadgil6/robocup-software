#pragma once

#include <gameplay/Behavior.hpp>

namespace Gameplay
{
	namespace Behaviors
	{
		class PivotKick: public SingleRobotBehavior
		{
			public:
				PivotKick(GameplayModule *gameplay);
				
				virtual bool run();
				
				bool done() const
				{
					return _state == State_Done;
				}
				
				bool aiming() const {
					return _state == State_Aim;
				}

				void restart();
				
				Geometry2d::Segment target;
				
			private:
				enum
				{
					State_Approach,
					State_Capture,
					State_Aim,
					State_Done
				} _state;
				
				bool _ccw;
				float _lastError;
				float _lastDelta;
				uint64_t _lastBallTime;
			};
	}
}