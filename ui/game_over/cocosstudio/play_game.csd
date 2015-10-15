<GameProjectFile>
  <PropertyGroup Type="Scene" Name="play_game" ID="04164498-190b-4306-a9a5-478d7f6b69c9" Version="2.3.2.3" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="root" Tag="28" ctype="GameNodeObjectData">
        <Size X="640.0000" Y="960.0000" />
        <Children>
          <AbstractNodeData Name="pan_touch" ActionTag="811253902" Tag="13" IconVisible="False" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" HorizontalEdge="BothEdge" VerticalEdge="BothEdge" TouchEnable="True" BackColorAlpha="102" ColorAngle="90.0000" ctype="PanelObjectData">
            <Size X="640.0000" Y="960.0000" />
            <AnchorPoint />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="1.0000" Y="1.0000" />
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="pan_all" ActionTag="-962645215" Tag="14" IconVisible="False" HorizontalEdge="BothEdge" VerticalEdge="BothEdge" LeftMargin="70.0000" RightMargin="70.0000" TopMargin="320.0000" BottomMargin="320.0000" TouchEnable="True" BackColorAlpha="102" ColorAngle="90.0000" Scale9Enable="True" LeftEage="50" RightEage="50" TopEage="50" BottomEage="50" ctype="PanelObjectData">
            <Size X="500.0000" Y="320.0000" />
            <Children>
              <AbstractNodeData Name="img_title_bg" ActionTag="601326576" Tag="15" IconVisible="False" HorizontalEdge="BothEdge" VerticalEdge="TopEdge" LeftMargin="90.0000" RightMargin="90.0000" TopMargin="-15.0000" BottomMargin="308.0000" Scale9Enable="True" LeftEage="29" RightEage="29" TopEage="4" BottomEage="4" Scale9OriginX="29" Scale9OriginY="4" Scale9Width="1" Scale9Height="49" ctype="ImageViewObjectData">
                <Size X="320.0000" Y="57.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="250.0000" Y="306.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" />
                <PreSize X="0.6400" Y="0.1629" />
                <FileData Type="Normal" Path="title_image.png" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="lbl_context_1" ActionTag="607925858" Tag="18" IconVisible="False" HorizontalEdge="BothEdge" VerticalEdge="TopEdge" LeftMargin="130.0000" RightMargin="130.0000" TopMargin="80.0000" BottomMargin="-11.5000" FontSize="30" LabelText="经典模式有存档！" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="240.0000" Y="35.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="250.0000" Y="222.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" />
                <PreSize X="0.2120" Y="0.0657" />
                <FontResource Type="Normal" Path="fzjzjt.ttf" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="lbl_context_2" ActionTag="935422059" Tag="19" IconVisible="False" HorizontalEdge="BothEdge" VerticalEdge="TopEdge" LeftMargin="180.0000" RightMargin="180.0000" TopMargin="130.0000" BottomMargin="-11.5000" FontSize="30" LabelText="是否继续游戏？" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="210.0000" Y="35.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="250.0000" Y="172.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" />
                <PreSize X="0.2120" Y="0.0657" />
                <FontResource Type="Normal" Path="fzjzjt.ttf" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="btn_start" ActionTag="-180473040" Tag="20" IconVisible="False" HorizontalEdge="LeftEdge" VerticalEdge="BottomEdge" LeftMargin="60.0000" RightMargin="284.0659" TopMargin="243.1840" BottomMargin="50.0000" TouchEnable="True" FontSize="30" ButtonText="重新开始" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="128" Scale9Height="38" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="158.0000" Y="60.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="139.0000" Y="80.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2739" Y="0.2195" />
                <PreSize X="0.3160" Y="0.1714" />
                <FontResource Type="Normal" Path="fzjzjt.ttf" Plist="" />
                <TextColor A="255" R="255" G="255" B="255" />
                <NormalFileData Type="Normal" Path="btn_158_60.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="btn_continue" ActionTag="-1709935226" Tag="21" IconVisible="False" HorizontalEdge="RightEdge" VerticalEdge="BottomEdge" LeftMargin="266.6734" RightMargin="60.0000" TopMargin="239.8442" BottomMargin="50.0000" TouchEnable="True" FontSize="30" ButtonText="继续游戏" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="128" Scale9Height="38" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="158.0000" Y="60.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="361.0000" Y="80.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.6913" Y="0.2290" />
                <PreSize X="0.3160" Y="0.1714" />
                <FontResource Type="Normal" Path="fzjzjt.ttf" Plist="" />
                <TextColor A="255" R="255" G="255" B="255" />
                <NormalFileData Type="Normal" Path="btn_158_60.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="lbl_title" ActionTag="-1548157854" Tag="22" IconVisible="False" HorizontalEdge="BothEdge" VerticalEdge="TopEdge" LeftMargin="220.0000" RightMargin="220.0000" TopMargin="-10.0000" BottomMargin="-11.5000" FontSize="45" LabelText="提示" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="90.0000" Y="53.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="250.0000" Y="303.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="243" G="243" B="247" />
                <PrePosition X="0.5000" />
                <PreSize X="0.2120" Y="0.0719" />
                <FontResource Type="Normal" Path="fzjzjt.ttf" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="320.0000" Y="480.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.7813" Y="0.3333" />
            <FileData Type="Normal" Path="bk_image_2.png" Plist="" />
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>