#pragma once

#include "kve_window.hpp"
#include "kve_pipeline.hpp"
#include "kve_swap_chain.hpp"

#include <memory>

namespace kve {
	class App {

	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		App();
		~App();

		App(const App&) = delete;
		App& operator=(const App&) = delete;

		void run();

	private:
		void createPipelineLayout();
		void createPipeline();
		void createCommandBuffers();
		void drawFrame();

		KveWindow kveWindow{ WIDTH, HEIGHT,"Vulkan!" };
		KveDevice kveDevice{ kveWindow };
		KveSwapChain kveSwapChain{ kveDevice, kveWindow.getExtent() };
		std::unique_ptr<KvePipeline> kvePipeline;

		VkPipelineLayout pipelineLayout;
		std::vector<VkCommandBuffer> commandBuffers;
	};
}