#pragma once
#include "../rage/joaat.hpp"

namespace rage
{
	enum class eThreadState : std::uint32_t
	{
		running,
		idle,
		killed,
		paused,
		breakpoint
	};

	class scrThreadContext
	{
	public:
		std::uint32_t m_thread_id;                 // 0x00
		joaat_t m_script_hash;                     // 0x04
		eThreadState m_state;                      // 0x08
		std::uint32_t m_instruction_pointer;       // 0x0C
		std::uint32_t m_frame_pointer;             // 0x10
		std::uint32_t m_stack_pointer;             // 0x14
		float m_timer_a;                           // 0x18
		float m_timer_b;                           // 0x1C
		float m_timer_c;                           // 0x20
		char m_padding1[0x2C];                     // 0x24
		std::uint32_t m_stack_size;                // 0x50
		std::uint32_t m_catch_instruction_pointer; // 0x54
		char m_padding2[0x50];                     // 0x58
	};
	static_assert(sizeof(scrThreadContext) == 0xA8);
}