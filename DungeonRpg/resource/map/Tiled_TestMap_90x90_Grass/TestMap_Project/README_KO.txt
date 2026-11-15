Tiled 테스트 맵 사용 안내

구성
- Maps/TestMap.tmx : 90 x 90 타일, 타일 크기 32 x 32
- Texture/TileSet/*.tsx : 원본 Tileset 정의
- Texture/*.png : Tileset 이미지

레이어
1. Ground       : 잔디 바탕
2. GrassAreas   : 돌 지형이 있던 영역을 잔디 타일로 교체한 구역
3. Wall         : 맵 외곽 및 내부의 짧은 벽 구간
4. Collision    : 외곽 및 내부 벽 충돌 사각형
5. SpawnPoints  : PlayerSpawn 위치

열기
1. ZIP을 원하는 폴더에 압축 해제합니다.
2. Tiled에서 Maps/TestMap.tmx를 엽니다.
3. TSX가 PNG를 상대 경로로 참조하므로 폴더 구조를 변경하지 마세요.

주의
- 맵은 2880 x 2880 픽셀입니다.
- TSX의 타일 크기는 제공된 파일에 기재된 32 x 32 설정을 사용했습니다.
- StoneGround 및 Wall의 타일 배치는 초기 테스트용입니다. Tiled에서 열어 실제 렌더링을 확인하고 필요하면 타일을 교체/수정하세요.
- Collision은 Tiled Object Layer 사각형입니다. C++ 엔진에서 TMX Object Layer를 파싱해야 실제 충돌에 적용됩니다.
- PlayerSpawn은 오브젝트 좌표로 제공됩니다.

수정 사항
- 기존 StoneGround 영역의 모양과 연결 통로는 유지하고, 해당 영역의 타일을 TX Tileset Grass 타일(0~31)로 교체했습니다.
- Stone Ground Tileset은 맵에서 참조하지 않도록 제외했습니다. 원본 파일은 Texture/TileSet 폴더에 보관되어 있습니다.
