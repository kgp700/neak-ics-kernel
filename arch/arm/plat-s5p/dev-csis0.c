/*
 * Copyright (C) 2010-2011 Samsung Electronics Co., Ltd.
 *
 * S5P series device definition for MIPI-CSIS channel 0
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/platform_device.h>
#include <mach/map.h>
#include <plat/mipi_csis.h>

static struct resource s5p_mipi_csis0_resource[] = {
	[0] = {
		.start = S5P_PA_MIPI_CSIS0,
		.end   = S5P_PA_MIPI_CSIS0 + SZ_16K - 1,
		.flags = IORESOURCE_MEM,
	},
	[1] = {
		.start = IRQ_MIPICSI0,
		.end   = IRQ_MIPICSI0,
		.flags = IORESOURCE_IRQ,
	}
};

struct platform_device s5p_device_mipi_csis0 = {
	.name		  = "s5p-mipi-csis",
	.id		  = 0,
	.num_resources	  = ARRAY_SIZE(s5p_mipi_csis0_resource),
	.resource	  = s5p_mipi_csis0_resource,
};

struct s5p_platform_mipi_csis s5p_mipi_csis0_default_data __initdata = {
	.clk_rate 	= 166000000,
	.lanes		= 2,
	.alignment	= 32,
	.hs_settle	= 12,
	.phy_enable	= s5p_csis_phy_enable,
};
