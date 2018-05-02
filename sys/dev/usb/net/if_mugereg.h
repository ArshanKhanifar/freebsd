/*-
 * SPDX-License-Identifier: BSD-2-Clause-FreeBSD
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD$
 */

/*
 * Definitions for the Microchip LAN7800 USB-to-Ethernet controllers.
 *
 * This information was mostly taken from the LAN7800 manual. However,
 * some undocumented registers come from the Linux driver (lan78xx.h).
 *
 */

#ifndef _IF_MUGEREG_H_
#define _IF_MUGEREG_H_

/* USB Vendor Requests */

#define MUGE_UR_WRITE_REG	0xA0
#define MUGE_UR_READ_REG	0xA1
#define MUGE_UR_GET_STATS	0xA2

/* Device ID and revision register */

#define MUGE_ID_REV			0x000
#define MUGE_ID_REV_CHIP_ID_MASK_	0xFFFF0000UL
#define MUGE_ID_REV_CHIP_REV_MASK_	0x0000FFFFUL

/* Device interrupt status register. */

#define MUGE_INT_STS				0x00C
#define MUGE_INT_STS_CLEAR_ALL_		0xFFFFFFFFUL

/* Hardware Configuration Register. */

#define MUGE_HW_CFG			0x010
#define MUGE_HW_CFG_LED3_EN_		(0x1UL << 23)
#define MUGE_HW_CFG_LED2_EN_		(0x1UL << 22)
#define MUGE_HW_CFG_LED1_EN_		(0x1UL << 21)
#define MUGE_HW_CFG_LEDO_EN_		(0x1UL << 20)
#define MUGE_HW_CFG_MEF_		(0x1UL << 4)
#define MUGE_HW_CFG_ETC_		(0x1UL << 3)
#define MUGE_HW_CFG_LRST_		(0x1UL << 1)	/* Lite reset */
#define MUGE_HW_CFG_SRST_		(0x1UL << 0)	/* Soft reset */

/* Power Management Control Register. */

#define MUGE_PMT_CTL			0x014
#define MUGE_PMT_CTL_PHY_RST_	(0x1UL << 4)	/* PHY reset */
#define MUGE_PMT_CTL_WOL_EN_		(0x1UL << 3)	/* PHY wake-on-lan enable */
#define MUGE_PMT_CTL_PHY_WAKE_EN_	(0x1UL << 2)	/* PHY interrupt as a wake up event*/

/* GPIO Configuration 0 Register. */

#define GPIO_CFG0				0x018

/* GPIO Configuration 1 Register. */

#define GPIO_CFG1				0x01C

/* GPIO wake enable and polarity register. */

#define GPIO_WAKE				0x020

/* RX Command A */

#define MUGE_RX_CMD_A_RED_		(0x1UL << 22)	/* Receive Error Detected */
#define MUGE_RX_CMD_A_ICSM_		(0x1UL << 14)
#define MUGE_RX_CMD_A_LEN_MASK_	0x00003FFFUL

/* TX Command A */

#define MUGE_TX_CMD_A_LEN_MASK_	0x000FFFFFUL
#define MUGE_TX_CMD_A_FCS_		(0x1UL << 22)

/* Data Port Select Register */

#define MUGE_DP_SEL			0x024
#define MUGE_DP_SEL_DPRDY_		(0x1UL << 31)
#define MUGE_DP_SEL_RSEL_VLAN_DA_	(0x1UL << 0)	/* RFE VLAN and DA Hash Table */
#define MUGE_DP_SEL_RSEL_MASK_	0x0000000F
#define MUGE_DP_SEL_VHF_HASH_LEN	16
#define MUGE_DP_SEL_VHF_VLAN_LEN	128

/* Data Port Command Register */

#define MUGE_DP_CMD			0x028
#define MUGE_DP_CMD_WRITE_		(0x1UL << 0)		/* 1 for write */
#define MUGE_DP_CMD_READ_		(0x0UL << 0)		/* 0 for read */

/* Data Port Address Register */

#define MUGE_DP_ADDR		0x02C

/* Data Port Data Register */

#define MUGE_DP_DATA		0x030

/* EEPROM Command Register */

#define MUGE_E2P_CMD			0x040
#define MUGE_E2P_CMD_MASK_		0x70000000UL
#define MUGE_E2P_CMD_ADDR_MASK_	0x000001FFUL
#define MUGE_E2P_CMD_BUSY_		(0x1UL << 31)
#define MUGE_E2P_CMD_READ_		(0x0UL << 28)
#define MUGE_E2P_CMD_WRITE_		(0x3UL << 28)
#define MUGE_E2P_CMD_ERASE_		(0x5UL << 28)
#define MUGE_E2P_CMD_RELOAD_		(0x7UL << 28)
#define MUGE_E2P_CMD_TIMEOUT_	(0x1UL << 10)
#define MUGE_E2P_MAC_OFFSET		0x01
#define MUGE_E2P_INDICATOR_OFFSET	0x00

/* EEPROM Data Register */

#define MUGE_E2P_DATA		0x044
#define MUGE_E2P_INDICATOR		0xA5	/* Indicates an EEPROM is present */

/* Packet sizes. */

#define MUGE_SS_USB_PKT_SIZE		1024
#define MUGE_HS_USB_PKT_SIZE		512
#define MUGE_FS_USB_PKT_SIZE		64

/* Receive Filtering Engine Control Register */

#define MUGE_RFE_CTL			0x0B0
#define MUGE_RFE_CTL_IGMP_COE_	(0x1U << 14)
#define MUGE_RFE_CTL_ICMP_COE_	(0x1U << 13)
#define MUGE_RFE_CTL_TCPUDP_COE_	(0x1U << 12)
#define MUGE_RFE_CTL_IP_COE_		(0x1U << 11)
#define MUGE_RFE_CTL_BCAST_EN_	(0x1U << 10)
#define MUGE_RFE_CTL_MCAST_EN_	(0x1U << 9)
#define MUGE_RFE_CTL_UCAST_EN_	(0x1U << 8)
#define MUGE_RFE_CTL_VLAN_FILTER_	(0x1U << 5)
#define MUGE_RFE_CTL_MCAST_HASH_	(0x1U << 3)
#define MUGE_RFE_CTL_DA_PERFECT_	(0x1U << 1)

/* End address of the RX FIFO */

#define MUGE_FCT_RX_FIFO_END		0x0C8
#define MUGE_FCT_RX_FIFO_END_MASK_	0x0000007FUL
#define MUGE_MAX_RX_FIFO_SIZE	(12 * 1024)

/* End address of the TX FIFO */

#define MUGE_FCT_TX_FIFO_END		0x0CC
#define MUGE_FCT_TX_FIFO_END_MASK_	0x0000003FUL
#define MUGE_MAX_TX_FIFO_SIZE	(12 * 1024)

/* USB Configuration Register 0 */

#define MUGE_USB_CFG0	0x080
#define MUGE_USB_CFG_BIR_	(0x1U << 6)	/* Bulk-In Empty response */
#define MUGE_USB_CFG_BCE_	(0x1U << 5)	/* Burst Cap Enable */

/* USB Configuration Register 1 */

#define MUGE_USB_CFG1	0x084

/* USB Configuration Register 2 */

#define MUGE_USB_CFG2	0x088

/* USB bConfigIndex: it only has one configuration. */

#define MUGE_CONFIG_INDEX	0

/* Burst Cap Register */

#define MUGE_BURST_CAP		0x090
#define MUGE_DEFAULT_BURST_CAP_SIZE	MUGE_MAX_TX_FIFO_SIZE

/* Bulk-In Delay Register */

#define MUGE_BULK_IN_DLY		0x094
#define MUGE_DEFAULT_BULK_IN_DELAY	0x0800

/* Interrupt Endpoint Control Register */

#define MUGE_INT_EP_CTL		0x098
#define MUGE_INT_ENP_PHY_INT		(0x1U << 17)	/* PHY Enable */

/* Registers on the phy, accessed via MII/MDIO */

#define MUGE_PHY_INTR_STAT		25
#define MUGE_PHY_INTR_MASK		26
#define MUGE_PHY_INTR_LINK_CHANGE	(0x1U << 13)
#define MUGE_PHY_INTR_ANEG_COMP	(0x1U << 10)
#define MUGE_EXT_PAGE_ACCESS		0x1F
#define MUGE_EXT_PAGE_SPACE_0	0x0000
#define MUGE_EXT_PAGE_SPACE_1	0x0001
#define MUGE_EXT_PAGE_SPACE_2	0x0002

/* Extended Register Page 1 Space */

#define MUGE_EXT_MODE_CTRL			0x0013
#define MUGE_EXT_MODE_CTRL_MDIX_MASK_	0x000C
#define MUGE_EXT_MODE_CTRL_AUTO_MDIX_	0x0000

/* FCT Flow Control Threshold Register */

#define MUGE_FCT_FLOW			0x0D0

/* FCT RX FIFO Control Register */

#define MUGE_FCT_RX_CTL			0x0C0

/* FCT TX FIFO Control Register */

#define MUGE_FCT_TX_CTL			0x0C4
#define MUGE_FCT_TX_CTL_EN_			(0x1U << 31)

/* MAC Control Register */

#define MUGE_MAC_CR				0x100
#define MUGE_MAC_CR_AUTO_DUPLEX_		(0x1U << 12)	/* Automatic Duplex Detection */
#define MUGE_MAC_CR_AUTO_SPEED_		(0x1U << 11)

/* MAC Receive Register */

#define MUGE_MAC_RX				0x104
#define MUGE_MAC_RX_MAX_FR_SIZE_MASK_	0x3FFF0000
#define MUGE_MAC_RX_MAX_FR_SIZE_SHIFT_	16
#define MUGE_MAC_RX_EN_			(0x1U << 0)	/* Enable Receiver */

/* MAC Transmit Register */

#define MUGE_MAC_TX				0x108
#define MUGE_MAC_TX_TXEN_			(0x1U << 0)	/* Enable Transmitter */

/* Flow Control Register */

#define MUGE_FLOW				0x10C
#define MUGE_FLOW_CR_TX_FCEN_		(0x1U << 30)	/* TX Flow Control Enable */
#define MUGE_FLOW_CR_RX_FCEN_		(0x1U << 29)	/* RX Flow Control Enable */

/* MAC Receive Address Registers */

#define MUGE_RX_ADDRH			0x118	/* High */
#define MUGE_RX_ADDRL			0x11C	/* Low */

/* MII Access Register */

#define MUGE_MII_ACCESS			0x120
#define MUGE_MII_BUSY_			(0x1UL << 0)
#define MUGE_MII_READ_			(0x0UL << 1)
#define MUGE_MII_WRITE_			(0x1UL << 1)

/* MII Data Register */

#define MUGE_MII_DATA			0x124

 /* MAC address perfect filter registers (ADDR_FILTx) */

#define MUGE_PFILTER_BASE			0x400
#define MUGE_PFILTER_HIX			0x00
#define MUGE_PFILTER_LOX			0x04
#define MUGE_NUM_PFILTER_ADDRS_		33
#define MUGE_PFILTER_ADDR_VALID_		(0x1UL << 31)
#define MUGE_PFILTER_ADDR_TYPE_SRC_		(0x1UL << 30)
#define MUGE_PFILTER_ADDR_TYPE_DST_		(0x0UL << 30)
#define MUGE_PFILTER_HI(index)		(MUGE_PFILTER_BASE + (8 * (index)) + (MUGE_PFILTER_HIX))
#define MUGE_PFILTER_LO(index)		(MUGE_PFILTER_BASE + (8 * (index)) + (MUGE_PFILTER_LOX))

/*
 * These registers are not documented in the datasheet. Stolen
 * from the Linux driver.
 */

#define MUGE_OTP_BASE_ADDR			0x01000
#define MUGE_OTP_PWR_DN			(MUGE_OTP_BASE_ADDR + 4 * 0x00)
#define MUGE_OTP_PWR_DN_PWRDN_N		0x01
#define MUGE_OTP_ADDR1			(MUGE_OTP_BASE_ADDR + 4 * 0x01)
#define MUGE_OTP_ADDR1_15_11			0x1F
#define MUGE_OTP_ADDR2			(MUGE_OTP_BASE_ADDR + 4 * 0x02)
#define MUGE_OTP_ADDR2_10_3			0xFF
#define MUGE_OTP_ADDR3			(MUGE_OTP_BASE_ADDR + 4 * 0x03)
#define MUGE_OTP_ADDR3_2_0			0x03
#define MUGE_OTP_RD_DATA			(MUGE_OTP_BASE_ADDR + 4 * 0x06)
#define MUGE_OTP_FUNC_CMD			(MUGE_OTP_BASE_ADDR + 4 * 0x08)
#define MUGE_OTP_FUNC_CMD_RESET		0x04
#define MUGE_OTP_FUNC_CMD_PROGRAM_		0x02
#define MUGE_OTP_FUNC_CMD_READ_		0x01
#define MUGE_OTP_MAC_OFFSET			0x01
#define MUGE_OTP_INDICATOR_OFFSET		0x00
#define MUGE_OTP_INDICATOR_1			0xF3
#define MUGE_OTP_INDICATOR_2			0xF7
#define MUGE_OTP_CMD_GO			(MUGE_OTP_BASE_ADDR + 4 * 0x0A)
#define MUGE_OTP_CMD_GO_GO_			0x01
#define MUGE_OTP_STATUS			(MUGE_OTP_BASE_ADDR + 4 * 0x0A)
#define MUGE_OTP_STATUS_OTP_LOCK_		0x10
#define MUGE_OTP_STATUS_BUSY_		0x01

/* Some unused registers, from the data sheet. */

#define MUGE_BOS_ATTR			0x050
#define MUGE_SS_ATTR				0x054
#define MUGE_HS_ATTR				0x058
#define MUGE_FS_ATTR				0x05C
#define MUGE_STRNG_ATTR0			0x060
#define MUGE_STRNG_ATTR1			0x064
#define MUGE_FLAG_ATTR			0x068
#define MUGE_SW_GP_1				0x06C
#define MUGE_SW_GP_2				0x070
#define MUGE_SW_GP_3				0x074
#define MUGE_VLAN_TYPE			0x0B4
#define MUGE_RX_DP_STOR			0x0D4
#define MUGE_TX_DP_STOR			0x0D8
#define MUGE_LTM_BELT_IDLE0			0x0E0
#define MUGE_LTM_BELT_IDLE1			0x0E4
#define MUGE_LTM_BELT_ACT0			0x0E8
#define MUGE_LTM_BELT_ACT1			0x0EC
#define MUGE_LTM_INACTIVE0			0x0F0
#define MUGE_LTM_INACTIVE1			0x0F4

#define MUGE_RAND_SEED			0x110
#define MUGE_ERR_STS				0x114

#define MUGE_EEE_TX_LPI_REQUEST_DELAY_CNT	0x130
#define MUGE_EEE_TW_TX_SYS			0x134
#define MUGE_EEE_TX_LPI_AUTO_REMOVAL_DELAY	0x138

#define MUGE_WUCSR1				0x140
#define MUGE_WK_SRC				0x144
#define MUGE_WUF_CFG_BASE			0x150
#define MUGE_WUF_MASK_BASE			0x200
#define MUGE_WUCSR2				0x600

#define MUGE_NSx_IPV6_ADDR_DEST_0		0x610
#define MUGE_NSx_IPV6_ADDR_DEST_1		0x614
#define MUGE_NSx_IPV6_ADDR_DEST_2		0x618
#define MUGE_NSx_IPV6_ADDR_DEST_3		0x61C

#define MUGE_NSx_IPV6_ADDR_SRC_0		0x620
#define MUGE_NSx_IPV6_ADDR_SRC_1		0x624
#define MUGE_NSx_IPV6_ADDR_SRC_2		0x628
#define MUGE_NSx_IPV6_ADDR_SRC_3		0x62C

#define MUGE_NSx_ICMPV6_ADDR0_0		0x630
#define MUGE_NSx_ICMPV6_ADDR0_1		0x634
#define MUGE_NSx_ICMPV6_ADDR0_2		0x638
#define MUGE_NSx_ICMPV6_ADDR0_3		0x63C

#define MUGE_NSx_ICMPV6_ADDR1_0		0x640
#define MUGE_NSx_ICMPV6_ADDR1_1		0x644
#define MUGE_NSx_ICMPV6_ADDR1_2		0x648
#define MUGE_NSx_ICMPV6_ADDR1_3		0x64C

#define MUGE_NSx_IPV6_ADDR_DEST		0x650
#define MUGE_NSx_IPV6_ADDR_SRC		0x660
#define MUGE_NSx_ICMPV6_ADDR0		0x670
#define MUGE_NSx_ICMPV6_ADDR1		0x680

#define MUGE_SYN_IPV4_ADDR_SRC		0x690
#define MUGE_SYN_IPV4_ADDR_DEST		0x694
#define MUGE_SYN_IPV4_TCP_PORTS		0x698

#define MUGE_SYN_IPV6_ADDR_SRC_0		0x69C
#define MUGE_SYN_IPV6_ADDR_SRC_1		0x6A0
#define MUGE_SYN_IPV6_ADDR_SRC_2		0x6A4
#define MUGE_SYN_IPV6_ADDR_SRC_3		0x6A8

#define MUGE_SYN_IPV6_ADDR_DEST_0		0x6AC
#define MUGE_SYN_IPV6_ADDR_DEST_1		0x6B0
#define MUGE_SYN_IPV6_ADDR_DEST_2		0x6B4
#define MUGE_SYN_IPV6_ADDR_DEST_3		0x6B8

#define MUGE_SYN_IPV6_TCP_PORTS		0x6BC
#define MUGE_ARP_SPA				0x6C0
#define MUGE_ARP_TPA				0x6C4
#define MUGE_PHY_DEV_ID			0x700

#endif /* _IF_MUGEREG_H_ */
