#define DT_DRV_COMPAT silabs_gecko_dma

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(dma_gecko);

#include <zephyr/device.h>
#include <zephyr/drivers/dma.h>
#include "dmadrv.h"


static int gecko_dma_config(const struct device *dev, uint32_t channel,
			    struct dma_config *cfg) {
	return 0;
}

static int gecko_dma_reload(const struct device *dev, uint32_t channel,
				     uint32_t src, uint32_t dst, size_t size) {
	return 0;
}

int gecko_dma_start(const struct device *dev, uint32_t channel) {
	return 0;
}

int gecko_dma_stop(const struct device *dev, uint32_t channel) {
	return 0;
}

static int gecko_dma_init(const struct device *dev) {
	LOG_DBG("Gecko DMA init");
	IRQ_CONNECT(DT_INST_IRQ(0, irq), DT_INST_IRQ(0, priority),
		    LDMA_IRQHandler, DEVICE_DT_INST_GET(0), 0);
	return 0;
}

static const struct dma_driver_api gecko_dma_driver_api = {
	.config = gecko_dma_config,
	.reload = gecko_dma_reload,
	.start = gecko_dma_start,
	.stop = gecko_dma_stop,
};

DEVICE_DT_INST_DEFINE(0, &gecko_dma_init, NULL,
		      NULL /* Data */, NULL /* Config */, POST_KERNEL,
		      CONFIG_DMA_INIT_PRIORITY, &gecko_dma_driver_api);
