<!--
	FNI
	
	Copyright 2011-2016 IS2T. All rights reserved.
	Modification and distribution is permitted under certain conditions.
	IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
-->
<nativesInterface>

	<nativesPool name="com.is2t.microui.MicroUIDisplayNativesPool">
		
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.initAndGetNextGraphicsContextId(int)int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.getDisplayPumpSize(int)int"/>
		
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.getHeight(int)int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.getWidth(int)int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.getNbBitsPerPixel(int)int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.isColor(int)boolean"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.getNumberOfColors(int)int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.getNumberOfAlphaLevels(int)int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.isDoubleBuffered(int)boolean"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.hasBacklight(int)boolean"/>
		
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.setContrast(int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.getContrast(int)int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.setBacklight(int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.getBacklight(int)int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.backlightOn(int,boolean)void"/>
		
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.linkOffscreen(int,boolean)int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.openOffScreen(int,int,int)int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.closeOffScreen(int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.flushScreen(int)void"/>
		
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawPixel(int,int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawHLine(int,int,int,int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawVLine(int,int,int,int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawLine(int,int,int,int,int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawRect(int,int,int,int,int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawArc(int,int,int,int,int,int,int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.fillArc(int,int,int,int,int,int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawEllipse(int,int,int,int,int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.fillEllipse(int,int,int,int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawCircle(int,int,int,int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.fillCircle(int,int,int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawRoundRect(int,int,int,int,int,int,int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawPolygon(int,int[],int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.fillPolygon(int,int[],int)boolean"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.getFillPolygonMaxEdges()int"/>
		
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawAAPoint(int,int,int,int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawAALine(int,int,int,int,int,int,int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawAACircleArc(int,int,int,int,int,int,int,int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawAAEllipse(int,int,int,int,int,int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawAACircle(int,int,int,int,int,int)void"/>
		
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawPoint(int,int,int,boolean)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawChars(int,int,int,int,char[],int,int,int,boolean)int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawDeformedChars(int,int,int,int,char[],int,int,int,float,float,boolean)int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawRegion(int,int,int,int,int,int,int,int,int,boolean)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawImageWithTransformation(int,int,int,int,int,int,int,int,int,int,boolean)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawImageWithRotation(int,int,int,int,int,int,int,int,boolean,boolean,boolean)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawDeformedImage(int,int,int[])void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawScaledImage(int,int,int,int,float,int,boolean)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.drawARGB(int,int[],int,int,int,int,int,int)void"/>
		
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.readPixel(int,int,int)int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.getARGB(int,int[],int,int,int,int,int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.collidesWith(int,int,int,int,int,int,int,int,int,int,int,int,int)boolean"/>
		
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.getDisplayColor(int,int)int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.setEllipsis(int,boolean)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.setClipRect(int,int,int,int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.setAvailableColor(int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.setFade(int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.setThickness(int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.setBackgroundColor(int,int,boolean)void"/>
		
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.loadImageFromPath(byte[],int,boolean,boolean,int[])int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.loadImageFromBytes(byte[],int,int,int[])int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.convertImage(int,int,int,int,int,int)int"/>
		
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.addInternalFont(byte[],int,int,boolean)int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.closeFont(int)void"/>
			
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.openFlyingImage(int,int,int)int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.closeFlyingImage(int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.showFlyingImage(int,boolean)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.changeBackground(int,boolean)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.setFlyingImagePosition(int,int,int)void"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.isShownFlyingImage(int)boolean"/>
		
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.getFontStylesAndFilters(int)int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.getFontHeight(int)int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.getFontBaseline(int)int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.getArraySize(int,int)int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.getFontDescriptor(int,byte[])int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.getFontIdentifiers(int,int[])int"/>
		<native name="com.is2t.microbsp.microui.natives.NSystemDisplay.charsWidth(int,char[],int,int)int"/>
		
	</nativesPool>
	
</nativesInterface>