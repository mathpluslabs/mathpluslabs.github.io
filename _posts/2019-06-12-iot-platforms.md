---
layout: default
title:  "Amazing IoT Development Platform"
---

### Amazing IoT Development Platforms, just my favorite highlights that are unique, updates soon - 6/12/2019
- balena.io, formerly resin.io
    - Linux container based OS for numerous hardware platforms called balenaOS
        - Runs their own version of docker optimized for embedded hardware called the balenaEngine
        - Ability to push docker applications to groups of devices using balenaCloud
        - Remote programming capability through balenaCloud, with the capability to ssh into containers and host OS
    - Balena created their own hardware development platform, the balena fin
        - Based on the pi 3 compute module
        - Very reasonable pricing for the hardware, note it does not include the pi module
        - Nice amount of I/O expandability
        	- Cellular modems through PCIe
        	- Classic pi pinout for all "hats" you can imagine
        	- My personal favorite an actual voltage input that is appropriate for industrial applications, 6-24V input voltage
        	- Lastly and most importantly, it has 8, 16, 32, and 64 GB on board eMMC as opposed to an SD card

- particle.io, formerly spark.io
	- Particle cloud
		- Management of devices
		- Web IDE that is able to push firmware and application updates to devices over the network
		- Data usage information
		- Webhooks to connect cloud values to other platforms
		- Cost is reasonable, I'm most familiar with cellular and seems slightly high but that includes all other cloud functionality as a one and done cost
	- Micro controller (MCU) mesh networking based OS
		- Already said above but the ability to flash these MCUs remotely is beyond satisfying
		- The OS is frequently updated
		- OS is mostly agnostic to the hardware so the core of your code will work with whatever particle hardware you choose
		- Very similar to an arduino plus the cloud and the hardware options
	- Multiple hardware options
		- Current lineup has a compatible pinout with the adafruit feather
		- Cellular connectivity with mesh
		- Cellular accepts 3rd party sim cards
		- Wifi connectivity with mesh
		- Mesh endpoints and repeaters
		- Ethernet connectivity through the use of "wings"
		- Works with most adafruit feather "wings" and code libraries

#### Note that there is lots of information I haven't talked about, these are just the highlights and you can always read the full specs on their websites