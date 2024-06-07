#include "sm64.h"
#include "types.h"
#include "characters.h"
#include "hud.h"
#include "model_ids.h"
#include "object_constants.h"
#include "sounds.h"
#include "luigi_sounds.h"
#include "wario_sounds.h"
#include "toad_sounds.h"
#include "pc/configfile.h"
#include "audio/external.h"
#include "engine/graph_node.h"
#include "pc/lua/smlua.h"

extern Gfx mario_cap_seg3_dl_03022F48[];
extern Gfx mario_cap_m_logo_decal[];
extern Gfx luigi_cap_seg3_dl_03022F48[];
extern Gfx luigi_cap_l_logo_decal[];
extern Gfx toad_cap_Cap_mesh_layer_1[];
extern Gfx toad_cap_Cap_mesh_layer_5[];
extern Gfx waluigi_cap_seg3_dl_03022F48[];
extern Gfx wario_cap_seg3_dl_03022F48[];

extern ALIGNED8 const u8 texture_hud_char_mario_head[];
extern ALIGNED8 const u8 texture_hud_char_luigi_head[];
extern ALIGNED8 const u8 texture_hud_char_toad_head[];
extern ALIGNED8 const u8 texture_hud_char_waluigi_head[];
extern ALIGNED8 const u8 texture_hud_char_wario_head[];

struct Character gCharacters[CT_MAX] = {
    [CT_MARIO] = {
        .type                  = CT_MARIO,
        .name                  = "Mario",
        .hudHead               = '(',
        .hudHeadTexture        = { .texture = (u8*)texture_hud_char_mario_head, .bitSize = 8, .width = 16, .height = 16, .name = "texture_hud_char_mario_head" },
        .cameraHudHead         = GLYPH_CAM_MARIO_HEAD,
        .modelId               = MODEL_MARIO,
        .capModelId            = MODEL_MARIOS_CAP,
        .capMetalModelId       = MODEL_MARIOS_METAL_CAP,
        .capWingModelId        = MODEL_MARIOS_WING_CAP,
        .capMetalWingModelId   = MODEL_MARIOS_WINGED_METAL_CAP,
        .capEnemyLayer         = LAYER_ALPHA,
        .capEnemyGfx           = mario_cap_seg3_dl_03022F48,
        .capEnemyDecalGfx      = mario_cap_m_logo_decal,
        .torsoRotMult          = 1.0f,
        // anim
        .animOffsetEnabled     = false,

        // character anims
        BASE_ANIMS(),

        // sounds
        .soundFreqScale        = 1.0f,
        .soundYahWahHoo        = SOUND_MARIO_YAH_WAH_HOO,
        .soundHoohoo           = SOUND_MARIO_HOOHOO,
        .soundYahoo            = SOUND_MARIO_YAHOO,
        .soundUh               = SOUND_MARIO_UH,
        .soundHrmm             = SOUND_MARIO_HRMM,
        .soundWah2             = SOUND_MARIO_WAH2,
        .soundWhoa             = SOUND_MARIO_WHOA,
        .soundEeuh             = SOUND_MARIO_EEUH,
        .soundAttacked         = SOUND_MARIO_ATTACKED,
        .soundOoof             = SOUND_MARIO_OOOF,
        .soundOoof2            = SOUND_MARIO_OOOF2,
        .soundHereWeGo         = SOUND_MARIO_HERE_WE_GO,
        .soundYawning          = SOUND_MARIO_YAWNING,
        .soundSnoring1         = SOUND_MARIO_SNORING1,
        .soundSnoring2         = SOUND_MARIO_SNORING2,
        .soundWaaaooow         = SOUND_MARIO_WAAAOOOW,
        .soundHaha             = SOUND_MARIO_HAHA,
        .soundHaha_2           = SOUND_MARIO_HAHA_2,
        .soundUh2              = SOUND_MARIO_UH2,
        .soundUh2_2            = SOUND_MARIO_UH2_2,
        .soundOnFire           = SOUND_MARIO_ON_FIRE,
        .soundDying            = SOUND_MARIO_DYING,
        .soundPantingCold      = SOUND_MARIO_PANTING_COLD,
        .soundPanting          = SOUND_MARIO_PANTING,
        .soundCoughing1        = SOUND_MARIO_COUGHING1,
        .soundCoughing2        = SOUND_MARIO_COUGHING2,
        .soundCoughing3        = SOUND_MARIO_COUGHING3,
        .soundPunchYah         = SOUND_MARIO_PUNCH_YAH,
        .soundPunchHoo         = SOUND_MARIO_PUNCH_HOO,
        .soundMamaMia          = SOUND_MARIO_MAMA_MIA,
        .soundGroundPoundWah   = SOUND_MARIO_GROUND_POUND_WAH,
        .soundDrowning         = SOUND_MARIO_DROWNING,
        .soundPunchWah         = SOUND_MARIO_PUNCH_WAH,
        .soundYahooWahaYippee  = SOUND_MARIO_YAHOO_WAHA_YIPPEE,
        .soundDoh              = SOUND_MARIO_DOH,
        .soundGameOver         = SOUND_MARIO_GAME_OVER,
        .soundHello            = SOUND_MARIO_HELLO,
        .soundPressStartToPlay = SOUND_MARIO_PRESS_START_TO_PLAY,
        .soundTwirlBounce      = SOUND_MARIO_TWIRL_BOUNCE,
        .soundSnoring3         = SOUND_MARIO_SNORING3,
        .soundSoLongaBowser    = SOUND_MARIO_SO_LONGA_BOWSER,
        .soundImaTired         = SOUND_MARIO_IMA_TIRED,
        .soundLetsAGo          = SOUND_MARIO_LETS_A_GO,
        .soundOkeyDokey        = SOUND_MARIO_OKEY_DOKEY,
    },

    [CT_LUIGI] = {
        .type                  = CT_LUIGI,
        .name                  = "Luigi",
        .hudHead               = ')',
        .hudHeadTexture        = { .texture = (u8*)texture_hud_char_luigi_head, .bitSize = 8, .width = 16, .height = 16, .name = "texture_hud_char_luigi_head" },
        .cameraHudHead         = GLYPH_CAM_LUIGI_HEAD,
        .modelId               = MODEL_LUIGI,
        .capModelId            = MODEL_LUIGIS_CAP,
        .capMetalModelId       = MODEL_LUIGIS_METAL_CAP,
        .capWingModelId        = MODEL_LUIGIS_WING_CAP,
        .capMetalWingModelId   = MODEL_LUIGIS_WINGED_METAL_CAP,
        .capEnemyLayer         = LAYER_ALPHA,
        .capEnemyGfx           = luigi_cap_seg3_dl_03022F48,
        .capEnemyDecalGfx      = luigi_cap_l_logo_decal,
        .torsoRotMult          = 1.0f,
        // anim
        .animOffsetEnabled     = false,

        // character anims
        BASE_ANIMS(),

        // sounds
        .soundFreqScale        = 1.0f,
        .soundYahWahHoo        = SOUND_LUIGI_YAH_WAH_HOO,
        .soundHoohoo           = SOUND_LUIGI_HOOHOO,
        .soundYahoo            = SOUND_LUIGI_YAHOO,
        .soundUh               = SOUND_LUIGI_UH,
        .soundHrmm             = SOUND_LUIGI_HRMM,
        .soundWah2             = SOUND_LUIGI_WAH2,
        .soundWhoa             = SOUND_LUIGI_WHOA,
        .soundEeuh             = SOUND_LUIGI_EEUH,
        .soundAttacked         = SOUND_LUIGI_ATTACKED,
        .soundOoof             = SOUND_LUIGI_OOOF,
        .soundOoof2            = SOUND_LUIGI_OOOF2,
        .soundHereWeGo         = SOUND_LUIGI_HERE_WE_GO,
        .soundYawning          = SOUND_LUIGI_YAWNING,
        .soundSnoring1         = SOUND_LUIGI_SNORING1,
        .soundSnoring2         = SOUND_LUIGI_SNORING2,
        .soundWaaaooow         = SOUND_LUIGI_WAAAOOOW,
        .soundHaha             = SOUND_LUIGI_HAHA,
        .soundHaha_2           = SOUND_LUIGI_HAHA_2,
        .soundUh2              = SOUND_LUIGI_UH2,
        .soundUh2_2            = SOUND_LUIGI_UH2_2,
        .soundOnFire           = SOUND_LUIGI_ON_FIRE,
        .soundDying            = SOUND_LUIGI_DYING,
        .soundPantingCold      = SOUND_LUIGI_PANTING_COLD,
        .soundPanting          = SOUND_LUIGI_PANTING,
        .soundCoughing1        = SOUND_LUIGI_COUGHING1,
        .soundCoughing2        = SOUND_LUIGI_COUGHING2,
        .soundCoughing3        = SOUND_LUIGI_COUGHING3,
        .soundPunchYah         = SOUND_LUIGI_PUNCH_YAH,
        .soundPunchHoo         = SOUND_LUIGI_PUNCH_HOO,
        .soundMamaMia          = SOUND_LUIGI_MAMA_MIA,
        .soundGroundPoundWah   = SOUND_LUIGI_GROUND_POUND_WAH,
        .soundDrowning         = SOUND_LUIGI_DROWNING,
        .soundPunchWah         = SOUND_LUIGI_PUNCH_WAH,
        .soundYahooWahaYippee  = SOUND_LUIGI_YAHOO_WAHA_YIPPEE,
        .soundDoh              = SOUND_LUIGI_DOH,
        .soundGameOver         = SOUND_LUIGI_GAME_OVER,
        .soundHello            = SOUND_LUIGI_HELLO,
        .soundPressStartToPlay = SOUND_LUIGI_PRESS_START_TO_PLAY,
        .soundTwirlBounce      = SOUND_LUIGI_TWIRL_BOUNCE,
        .soundSnoring3         = SOUND_LUIGI_SNORING3,
        .soundSoLongaBowser    = SOUND_LUIGI_SO_LONGA_BOWSER,
        .soundImaTired         = SOUND_LUIGI_IMA_TIRED,
        .soundLetsAGo          = SOUND_LUIGI_LETS_A_GO,
        .soundOkeyDokey        = SOUND_LUIGI_OKEY_DOKEY,
    },

    [CT_TOAD] = {
        .type                  = CT_TOAD,
        .name                  = "Toad",
        .hudHead               = '|',
        .hudHeadTexture        = { .texture = (u8*)texture_hud_char_toad_head, .bitSize = 8, .width = 16, .height = 16, .name = "texture_hud_char_toad_head" },
        .cameraHudHead         = GLYPH_CAM_TOAD_HEAD,
        .modelId               = MODEL_TOAD_PLAYER,
        .capModelId            = MODEL_TOADS_CAP,
        .capMetalModelId       = MODEL_TOADS_METAL_CAP,
        .capWingModelId        = MODEL_TOADS_WING_CAP,
        .capMetalWingModelId   = MODEL_TOADS_WINGED_METAL_CAP,
        .capEnemyLayer         = LAYER_ALPHA,
        .capEnemyGfx           = toad_cap_Cap_mesh_layer_1,
        .capEnemyDecalGfx      = toad_cap_Cap_mesh_layer_5,
        .torsoRotMult          = 1.0f,
        // anim
        .animOffsetEnabled     = false,

        // character anims
        BASE_ANIMS(),

        // sounds
        .soundFreqScale        = 1.0f,
        .soundYahWahHoo        = SOUND_TOAD_YAH_WAH_HOO,
        .soundHoohoo           = SOUND_TOAD_HOOHOO,
        .soundYahoo            = SOUND_TOAD_YAHOO,
        .soundUh               = SOUND_TOAD_UH,
        .soundHrmm             = SOUND_TOAD_HRMM,
        .soundWah2             = SOUND_TOAD_WAH2,
        .soundWhoa             = SOUND_TOAD_WHOA,
        .soundEeuh             = SOUND_TOAD_EEUH,
        .soundAttacked         = SOUND_TOAD_ATTACKED,
        .soundOoof             = SOUND_TOAD_OOOF,
        .soundOoof2            = SOUND_TOAD_OOOF2,
        .soundHereWeGo         = SOUND_TOAD_HERE_WE_GO,
        .soundYawning          = SOUND_TOAD_YAWNING,
        .soundSnoring1         = SOUND_TOAD_SNORING1,
        .soundSnoring2         = SOUND_TOAD_SNORING2,
        .soundWaaaooow         = SOUND_TOAD_WAAAOOOW,
        .soundHaha             = SOUND_TOAD_HAHA,
        .soundHaha_2           = SOUND_TOAD_HAHA_2,
        .soundUh2              = SOUND_TOAD_UH2,
        .soundUh2_2            = SOUND_TOAD_UH2_2,
        .soundOnFire           = SOUND_TOAD_ON_FIRE,
        .soundDying            = SOUND_TOAD_DYING,
        .soundPantingCold      = SOUND_TOAD_PANTING_COLD,
        .soundPanting          = SOUND_TOAD_PANTING,
        .soundCoughing1        = SOUND_TOAD_COUGHING1,
        .soundCoughing2        = SOUND_TOAD_COUGHING2,
        .soundCoughing3        = SOUND_TOAD_COUGHING3,
        .soundPunchYah         = SOUND_TOAD_PUNCH_YAH,
        .soundPunchHoo         = SOUND_TOAD_PUNCH_HOO,
        .soundMamaMia          = SOUND_TOAD_MAMA_MIA,
        .soundGroundPoundWah   = SOUND_TOAD_GROUND_POUND_WAH,
        .soundDrowning         = SOUND_TOAD_DROWNING,
        .soundPunchWah         = SOUND_TOAD_PUNCH_WAH,
        .soundYahooWahaYippee  = SOUND_TOAD_YAHOO_WAHA_YIPPEE,
        .soundDoh              = SOUND_TOAD_DOH,
        .soundGameOver         = SOUND_TOAD_GAME_OVER,
        .soundHello            = SOUND_TOAD_HELLO,
        .soundPressStartToPlay = SOUND_TOAD_PRESS_START_TO_PLAY,
        .soundTwirlBounce      = SOUND_TOAD_TWIRL_BOUNCE,
        .soundSnoring3         = SOUND_TOAD_SNORING3,
        .soundSoLongaBowser    = SOUND_TOAD_SO_LONGA_BOWSER,
        .soundImaTired         = SOUND_TOAD_IMA_TIRED,
        .soundLetsAGo          = SOUND_TOAD_LETS_A_GO,
        .soundOkeyDokey        = SOUND_TOAD_OKEY_DOKEY,
    },

    [CT_WALUIGI] = {
        .type                  = CT_WALUIGI,
        .name                  = "Waluigi",
        .hudHead               = ']',
        .hudHeadTexture        = { .texture = (u8*)texture_hud_char_waluigi_head, .bitSize = 8, .width = 16, .height = 16, .name = "texture_hud_char_waluigi_head" },
        .cameraHudHead         = GLYPH_CAM_WALUIGI_HEAD,
        .modelId               = MODEL_WALUIGI,
        .capModelId            = MODEL_WALUIGIS_CAP,
        .capMetalModelId       = MODEL_WALUIGIS_METAL_CAP,
        .capWingModelId        = MODEL_WALUIGIS_WING_CAP,
        .capMetalWingModelId   = MODEL_WALUIGIS_WINGED_METAL_CAP,
        .capEnemyLayer         = LAYER_OPAQUE,
        .capEnemyGfx           = waluigi_cap_seg3_dl_03022F48,
        .capEnemyDecalGfx      = NULL,
        .torsoRotMult          = 0.5f,
        // anim
        .animOffsetEnabled     = true,
        .animOffsetLowYPoint   = 11,
        .animOffsetFeet        = 25,
        .animOffsetHand        = -10,

        // character anims
        .animSlowLedgeGrab =                    MARIO_ANIM_SLOW_LEDGE_GRAB,
        .animFallOverBackwards =                MARIO_ANIM_FALL_OVER_BACKWARDS,
        .animBackwardAirKb =                    MARIO_ANIM_BACKWARD_AIR_KB,
        .animDyingOnBack =                      MARIO_ANIM_DYING_ON_BACK,
        .animBackflip =                         MARIO_ANIM_BACKFLIP,
        .animClimbUpPole =                      MARIO_ANIM_CLIMB_UP_POLE,
        .animGrabPoleShort =                    MARIO_ANIM_GRAB_POLE_SHORT,
        .animGrabPoleSwingPart1 =               MARIO_ANIM_GRAB_POLE_SWING_PART1,
        .animGrabPoleSwingPart2 =               MARIO_ANIM_GRAB_POLE_SWING_PART2,
        .animHandstandIdle =                    MARIO_ANIM_HANDSTAND_IDLE,
        .animHandstandJump =                    MARIO_ANIM_HANDSTAND_JUMP,
        .animStartHandstand =                   MARIO_ANIM_START_HANDSTAND,
        .animReturnFromHandstand =              MARIO_ANIM_RETURN_FROM_HANDSTAND,
        .animIdleOnPole =                       MARIO_ANIM_IDLE_ON_POLE,
        .animAPose =                            MARIO_ANIM_A_POSE,
        .animSkidOnGround =                     MARIO_ANIM_SKID_ON_GROUND,
        .animStopSkid =                         MARIO_ANIM_STOP_SKID,
        .animCrouchFromFastLongjump =           MARIO_ANIM_CROUCH_FROM_FAST_LONGJUMP,
        .animCrouchFromSlowLongjump =           MARIO_ANIM_CROUCH_FROM_SLOW_LONGJUMP,
        .animFastLongjump =                     MARIO_ANIM_FAST_LONGJUMP,
        .animSlowLongjump =                     MARIO_ANIM_SLOW_LONGJUMP,
        .animAirborneOnStomach =                MARIO_ANIM_AIRBORNE_ON_STOMACH,
        .animWalkWithLightObj =                 MARIO_ANIM_WALK_WITH_LIGHT_OBJ,
        .animRunWithLightObj =                  MARIO_ANIM_RUN_WITH_LIGHT_OBJ,
        .animSlowWalkWithLightObj =             MARIO_ANIM_SLOW_WALK_WITH_LIGHT_OBJ,
        .animShiveringWarmingHand =             MARIO_ANIM_SHIVERING_WARMING_HAND,
        .animShiveringReturnToIdle =            MARIO_ANIM_SHIVERING_RETURN_TO_IDLE,
        .animShivering =                        MARIO_ANIM_SHIVERING,
        .animClimbDownLedge =                   MARIO_ANIM_CLIMB_DOWN_LEDGE,
        .animCreditsWaving =                    MARIO_ANIM_CREDITS_WAVING,
        .animCreditsLookUp =                    MARIO_ANIM_CREDITS_LOOK_UP,
        .animCreditsReturnFromLookUp =          MARIO_ANIM_CREDITS_RETURN_FROM_LOOK_UP,
        .animCreditsRaiseHand =                 MARIO_ANIM_CREDITS_RAISE_HAND,
        .animCreditsLowerHand =                 MARIO_ANIM_CREDITS_LOWER_HAND,
        .animCreditsTakeOffCap =                MARIO_ANIM_CREDITS_TAKE_OFF_CAP,
        .animCreditsStartWalkLookUp =           MARIO_ANIM_CREDITS_START_WALK_LOOK_UP,
        .animCreditsLookBackThenRun =           MARIO_ANIM_CREDITS_LOOK_BACK_THEN_RUN,
        .animFinalBowserRaiseHandSpin =         MARIO_ANIM_FINAL_BOWSER_RAISE_HAND_SPIN,
        .animFinalBowserWingCapTakeOff =        MARIO_ANIM_FINAL_BOWSER_WING_CAP_TAKE_OFF,
        .animCreditsPeaceSign =                 MARIO_ANIM_CREDITS_PEACE_SIGN,
        .animStandUpFromLavaBoost =             MARIO_ANIM_STAND_UP_FROM_LAVA_BOOST,
        .animFireLavaBurn =                     MARIO_ANIM_FIRE_LAVA_BURN,
        .animWingCapFly =                       MARIO_ANIM_WING_CAP_FLY,
        .animHangOnOwl =                        MARIO_ANIM_HANG_ON_OWL,
        .animLandOnStomach =                    MARIO_ANIM_LAND_ON_STOMACH,
        .animAirForwardKb =                     MARIO_ANIM_AIR_FORWARD_KB,
        .animDyingOnStomach =                   MARIO_ANIM_DYING_ON_STOMACH,
        .animSuffocating =                      MARIO_ANIM_SUFFOCATING,
        .animCoughing =                         MARIO_ANIM_COUGHING,
        .animThrowCatchKey =                    MARIO_ANIM_THROW_CATCH_KEY,
        .animDyingFallOver =                    MARIO_ANIM_DYING_FALL_OVER,
        .animIdleOnLedge =                      MARIO_ANIM_IDLE_ON_LEDGE,
        .animFastLedgeGrab =                    MARIO_ANIM_FAST_LEDGE_GRAB,
        .animHangOnCeiling =                    MARIO_ANIM_HANG_ON_CEILING,
        .animPutCapOn =                         MARIO_ANIM_PUT_CAP_ON,
        .animTakeCapOffThenOn =                 MARIO_ANIM_TAKE_CAP_OFF_THEN_ON,
        .animQuicklyPutCapOn =                  MARIO_ANIM_QUICKLY_PUT_CAP_ON,
        .animHeadStuckInGround =                MARIO_ANIM_HEAD_STUCK_IN_GROUND,
        .animGroundPoundLanding =               MARIO_ANIM_GROUND_POUND_LANDING,
        .animTripleJumpGroundPound =            MARIO_ANIM_TRIPLE_JUMP_GROUND_POUND,
        .animStartGroundPound =                 MARIO_ANIM_START_GROUND_POUND,
        .animGroundPound =                      MARIO_ANIM_GROUND_POUND,
        .animBottomStuckInGround =              MARIO_ANIM_BOTTOM_STUCK_IN_GROUND,
        .animIdleWithLightObj =                 MARIO_ANIM_IDLE_WITH_LIGHT_OBJ,
        .animJumpLandWithLightObj =             MARIO_ANIM_JUMP_LAND_WITH_LIGHT_OBJ,
        .animJumpWithLightObj =                 MARIO_ANIM_JUMP_WITH_LIGHT_OBJ,
        .animFallLandWithLightObj =             MARIO_ANIM_FALL_LAND_WITH_LIGHT_OBJ,
        .animFallWithLightObj =                 MARIO_ANIM_FALL_WITH_LIGHT_OBJ,
        .animFallFromSlidingWithLightObj =      MARIO_ANIM_FALL_FROM_SLIDING_WITH_LIGHT_OBJ,
        .animSlidingOnBottomWithLightObj =      MARIO_ANIM_SLIDING_ON_BOTTOM_WITH_LIGHT_OBJ,
        .animStandUpFromSlidingWithLightObj =   MARIO_ANIM_STAND_UP_FROM_SLIDING_WITH_LIGHT_OBJ,
        .animRidingShell =                      MARIO_ANIM_RIDING_SHELL,
        .animWalking =                          WALUIGI_ANIM_WALKING,
        .animForwardFlip =                      MARIO_ANIM_FORWARD_FLIP,
        .animJumpRidingShell =                  MARIO_ANIM_JUMP_RIDING_SHELL,
        .animLandFromDoubleJump =               MARIO_ANIM_LAND_FROM_DOUBLE_JUMP,
        .animDoubleJumpFall =                   MARIO_ANIM_DOUBLE_JUMP_FALL,
        .animSingleJump =                       MARIO_ANIM_SINGLE_JUMP,
        .animLandFromSingleJump =               MARIO_ANIM_LAND_FROM_SINGLE_JUMP,
        .animAirKick =                          MARIO_ANIM_AIR_KICK,
        .animDoubleJumpRise =                   MARIO_ANIM_DOUBLE_JUMP_RISE,
        .animStartForwardSpinning =             MARIO_ANIM_START_FORWARD_SPINNING,
        .animThrowLightObject =                 MARIO_ANIM_THROW_LIGHT_OBJECT,
        .animFallFromSlideKick =                MARIO_ANIM_FALL_FROM_SLIDE_KICK,
        .animBendKnessRidingShell =             MARIO_ANIM_BEND_KNESS_RIDING_SHELL,
        .animLegsStuckInGround =                MARIO_ANIM_LEGS_STUCK_IN_GROUND,
        .animGeneralFall =                      MARIO_ANIM_GENERAL_FALL,
        .animGeneralLand =                      MARIO_ANIM_GENERAL_LAND,
        .animBeingGrabbed =                     MARIO_ANIM_BEING_GRABBED,
        .animGrabHeavyObject =                  MARIO_ANIM_GRAB_HEAVY_OBJECT,
        .animSlowLandFromDive =                 MARIO_ANIM_SLOW_LAND_FROM_DIVE,
        .animFlyFromCannon =                    MARIO_ANIM_FLY_FROM_CANNON,
        .animMoveOnWireNetRight =               MARIO_ANIM_MOVE_ON_WIRE_NET_RIGHT,
        .animMoveOnWireNetLeft =                MARIO_ANIM_MOVE_ON_WIRE_NET_LEFT,
        .animMissingCap =                       MARIO_ANIM_MISSING_CAP,
        .animPullDoorWalkIn =                   MARIO_ANIM_PULL_DOOR_WALK_IN,
        .animPushDoorWalkIn =                   MARIO_ANIM_PUSH_DOOR_WALK_IN,
        .animUnlockDoor =                       MARIO_ANIM_UNLOCK_DOOR,
        .animStartReachPocket =                 MARIO_ANIM_START_REACH_POCKET,
        .animReachPocket =                      MARIO_ANIM_REACH_POCKET,
        .animStopReachPocket =                  MARIO_ANIM_STOP_REACH_POCKET,
        .animGroundThrow =                      MARIO_ANIM_GROUND_THROW,
        .animGroundKick =                       MARIO_ANIM_GROUND_KICK,
        .animFirstPunch =                       MARIO_ANIM_FIRST_PUNCH,
        .animSecondPunch =                      MARIO_ANIM_SECOND_PUNCH,
        .animFirstPunchFast =                   MARIO_ANIM_FIRST_PUNCH_FAST,
        .animSecondPunchFast =                  MARIO_ANIM_SECOND_PUNCH_FAST,
        .animPickUpLightObj =                   MARIO_ANIM_PICK_UP_LIGHT_OBJ,
        .animPushing =                          MARIO_ANIM_PUSHING,
        .animStartRidingShell =                 MARIO_ANIM_START_RIDING_SHELL,
        .animPlaceLightObj =                    MARIO_ANIM_PLACE_LIGHT_OBJ,
        .animForwardSpinning =                  MARIO_ANIM_FORWARD_SPINNING,
        .animBackwardSpinning =                 MARIO_ANIM_BACKWARD_SPINNING,
        .animBreakdance =                       MARIO_ANIM_BREAKDANCE,
        .animRunning =                          WALUIGI_ANIM_RUNNING,
        .animRunningUnused =                    MARIO_ANIM_RUNNING_UNUSED,
        .animSoftBackKb =                       MARIO_ANIM_SOFT_BACK_KB,
        .animSoftFrontKb =                      MARIO_ANIM_SOFT_FRONT_KB,
        .animDyingInQuicksand =                 MARIO_ANIM_DYING_IN_QUICKSAND,
        .animIdleInQuicksand =                  MARIO_ANIM_IDLE_IN_QUICKSAND,
        .animMoveInQuicksand =                  MARIO_ANIM_MOVE_IN_QUICKSAND,
        .animElectrocution =                    MARIO_ANIM_ELECTROCUTION,
        .animShocked =                          MARIO_ANIM_SHOCKED,
        .animBackwardKb =                       MARIO_ANIM_BACKWARD_KB,
        .animForwardKb =                        MARIO_ANIM_FORWARD_KB,
        .animIdleHeavyObj =                     MARIO_ANIM_IDLE_HEAVY_OBJ,
        .animStandAgainstWall =                 MARIO_ANIM_STAND_AGAINST_WALL,
        .animSidestepLeft =                     MARIO_ANIM_SIDESTEP_LEFT,
        .animSidestepRight =                    MARIO_ANIM_SIDESTEP_RIGHT,
        .animStartSleepIdle =                   MARIO_ANIM_START_SLEEP_IDLE,
        .animStartSleepScratch =                MARIO_ANIM_START_SLEEP_SCRATCH,
        .animStartSleepYawn =                   MARIO_ANIM_START_SLEEP_YAWN,
        .animStartSleepSitting =                MARIO_ANIM_START_SLEEP_SITTING,
        .animSleepIdle =                        MARIO_ANIM_SLEEP_IDLE,
        .animSleepStartLying =                  MARIO_ANIM_SLEEP_START_LYING,
        .animSleepLying =                       MARIO_ANIM_SLEEP_LYING,
        .animDive =                             MARIO_ANIM_DIVE,
        .animSlideDive =                        MARIO_ANIM_SLIDE_DIVE,
        .animGroundBonk =                       MARIO_ANIM_GROUND_BONK,
        .animStopSlideLightObj =                MARIO_ANIM_STOP_SLIDE_LIGHT_OBJ,
        .animSlideKick =                        MARIO_ANIM_SLIDE_KICK,
        .animCrouchFromSlideKick =              MARIO_ANIM_CROUCH_FROM_SLIDE_KICK,
        .animSlideMotionless =                  MARIO_ANIM_SLIDE_MOTIONLESS,
        .animStopSlide =                        MARIO_ANIM_STOP_SLIDE,
        .animFallFromSlide =                    MARIO_ANIM_FALL_FROM_SLIDE,
        .animSlide =                            MARIO_ANIM_SLIDE,
        .animTiptoe =                           MARIO_ANIM_TIPTOE,
        .animTwirlLand =                        MARIO_ANIM_TWIRL_LAND,
        .animTwirl =                            MARIO_ANIM_TWIRL,
        .animStartTwirl =                       MARIO_ANIM_START_TWIRL,
        .animStopCrouching =                    MARIO_ANIM_STOP_CROUCHING,
        .animStartCrouching =                   MARIO_ANIM_START_CROUCHING,
        .animCrouching =                        MARIO_ANIM_CROUCHING,
        .animCrawling =                         MARIO_ANIM_CRAWLING,
        .animStopCrawling =                     MARIO_ANIM_STOP_CRAWLING,
        .animStartCrawling =                    MARIO_ANIM_START_CRAWLING,
        .animSummonStar =                       MARIO_ANIM_SUMMON_STAR,
        .animReturnStarApproachDoor =           MARIO_ANIM_RETURN_STAR_APPROACH_DOOR,
        .animBackwardsWaterKb =                 MARIO_ANIM_BACKWARDS_WATER_KB,
        .animSwimWithObjPart1 =                 MARIO_ANIM_SWIM_WITH_OBJ_PART1,
        .animSwimWithObjPart2 =                 MARIO_ANIM_SWIM_WITH_OBJ_PART2,
        .animFlutterkickWithObj =               MARIO_ANIM_FLUTTERKICK_WITH_OBJ,
        .animWaterActionEndWithObj =            MARIO_ANIM_WATER_ACTION_END_WITH_OBJ,
        .animStopGrabObjWater =                 MARIO_ANIM_STOP_GRAB_OBJ_WATER,
        .animWaterIdleWithObj =                 MARIO_ANIM_WATER_IDLE_WITH_OBJ,
        .animDrowningPart1 =                    MARIO_ANIM_DROWNING_PART1,
        .animDrowningPart2 =                    MARIO_ANIM_DROWNING_PART2,
        .animWaterDying =                       MARIO_ANIM_WATER_DYING,
        .animWaterForwardKb =                   MARIO_ANIM_WATER_FORWARD_KB,
        .animFallFromWater =                    MARIO_ANIM_FALL_FROM_WATER,
        .animSwimPart1 =                        MARIO_ANIM_SWIM_PART1,
        .animSwimPart2 =                        MARIO_ANIM_SWIM_PART2,
        .animFlutterkick =                      MARIO_ANIM_FLUTTERKICK,
        .animWaterActionEnd =                   MARIO_ANIM_WATER_ACTION_END,
        .animWaterPickUpObj =                   MARIO_ANIM_WATER_PICK_UP_OBJ,
        .animWaterGrabObjPart2 =                MARIO_ANIM_WATER_GRAB_OBJ_PART2,
        .animWaterGrabObjPart1 =                MARIO_ANIM_WATER_GRAB_OBJ_PART1,
        .animWaterThrowObj =                    MARIO_ANIM_WATER_THROW_OBJ,
        .animWaterIdle =                        MARIO_ANIM_WATER_IDLE,
        .animWaterStarDance =                   MARIO_ANIM_WATER_STAR_DANCE,
        .animReturnFromWaterStarDance =         MARIO_ANIM_RETURN_FROM_WATER_STAR_DANCE,
        .animGrabBowser =                       MARIO_ANIM_GRAB_BOWSER,
        .animSwingingBowser =                   MARIO_ANIM_SWINGING_BOWSER,
        .animReleaseBowser =                    MARIO_ANIM_RELEASE_BOWSER,
        .animHoldingBowser =                    MARIO_ANIM_HOLDING_BOWSER,
        .animHeavyThrow =                       MARIO_ANIM_HEAVY_THROW,
        .animWalkPanting =                      MARIO_ANIM_WALK_PANTING,
        .animWalkWithHeavyObj =                 MARIO_ANIM_WALK_WITH_HEAVY_OBJ,
        .animTurningPart1 =                     MARIO_ANIM_TURNING_PART1,
        .animTurningPart2 =                     MARIO_ANIM_TURNING_PART2,
        .animSlideflipLand =                    MARIO_ANIM_SLIDEFLIP_LAND,
        .animSlideflip =                        MARIO_ANIM_SLIDEFLIP,
        .animTripleJumpLand =                   MARIO_ANIM_TRIPLE_JUMP_LAND,
        .animTripleJump =                       MARIO_ANIM_TRIPLE_JUMP,
        .animFirstPerson =                      MARIO_ANIM_FIRST_PERSON,
        .animIdleHeadLeft =                     MARIO_ANIM_IDLE_HEAD_LEFT,
        .animIdleHeadRight =                    MARIO_ANIM_IDLE_HEAD_RIGHT,
        .animIdleHeadCenter =                   MARIO_ANIM_IDLE_HEAD_CENTER,
        .animHandstandLeft =                    MARIO_ANIM_HANDSTAND_LEFT,
        .animHandstandRight =                   MARIO_ANIM_HANDSTAND_RIGHT,
        .animWakeFromSleep =                    MARIO_ANIM_WAKE_FROM_SLEEP,
        .animWakeFromLying =                    MARIO_ANIM_WAKE_FROM_LYING,
        .animStartTiptoe =                      MARIO_ANIM_START_TIPTOE,
        .animSlidejump =                        MARIO_ANIM_SLIDEJUMP,
        .animStartWallkick =                    MARIO_ANIM_START_WALLKICK,
        .animStarDance =                        MARIO_ANIM_STAR_DANCE,
        .animReturnFromStarDance =              MARIO_ANIM_RETURN_FROM_STAR_DANCE,
        .animForwardSpinningFlip =              MARIO_ANIM_FORWARD_SPINNING_FLIP,
        .animTripleJumpFly =                    MARIO_ANIM_TRIPLE_JUMP_FLY,

        // sounds
        .soundFreqScale        = 0.99f,
        .soundYahWahHoo        = SOUND_LUIGI_YAH_WAH_HOO,
        .soundHoohoo           = SOUND_LUIGI_HOOHOO,
        .soundYahoo            = SOUND_LUIGI_YAHOO,
        .soundUh               = SOUND_LUIGI_UH,
        .soundHrmm             = SOUND_LUIGI_HRMM,
        .soundWah2             = SOUND_LUIGI_WAH2,
        .soundWhoa             = SOUND_LUIGI_WHOA,
        .soundEeuh             = SOUND_LUIGI_EEUH,
        .soundAttacked         = SOUND_LUIGI_ATTACKED,
        .soundOoof             = SOUND_LUIGI_OOOF,
        .soundOoof2            = SOUND_LUIGI_OOOF2,
        .soundHereWeGo         = SOUND_LUIGI_HERE_WE_GO,
        .soundYawning          = SOUND_LUIGI_YAWNING,
        .soundSnoring1         = SOUND_LUIGI_SNORING1,
        .soundSnoring2         = SOUND_LUIGI_SNORING2,
        .soundWaaaooow         = SOUND_LUIGI_WAAAOOOW,
        .soundHaha             = SOUND_LUIGI_HAHA,
        .soundHaha_2           = SOUND_LUIGI_HAHA_2,
        .soundUh2              = SOUND_LUIGI_UH2,
        .soundUh2_2            = SOUND_LUIGI_UH2_2,
        .soundOnFire           = SOUND_LUIGI_ON_FIRE,
        .soundDying            = SOUND_LUIGI_DYING,
        .soundPantingCold      = SOUND_LUIGI_PANTING_COLD,
        .soundPanting          = SOUND_LUIGI_PANTING,
        .soundCoughing1        = SOUND_LUIGI_COUGHING1,
        .soundCoughing2        = SOUND_LUIGI_COUGHING2,
        .soundCoughing3        = SOUND_LUIGI_COUGHING3,
        .soundPunchYah         = SOUND_LUIGI_PUNCH_YAH,
        .soundPunchHoo         = SOUND_LUIGI_PUNCH_HOO,
        .soundMamaMia          = SOUND_LUIGI_MAMA_MIA,
        .soundGroundPoundWah   = SOUND_LUIGI_GROUND_POUND_WAH,
        .soundDrowning         = SOUND_LUIGI_DROWNING,
        .soundPunchWah         = SOUND_LUIGI_PUNCH_WAH,
        .soundYahooWahaYippee  = SOUND_LUIGI_YAHOO_WAHA_YIPPEE,
        .soundDoh              = SOUND_LUIGI_DOH,
        .soundGameOver         = SOUND_LUIGI_GAME_OVER,
        .soundHello            = SOUND_LUIGI_HELLO,
        .soundPressStartToPlay = SOUND_LUIGI_PRESS_START_TO_PLAY,
        .soundTwirlBounce      = SOUND_LUIGI_TWIRL_BOUNCE,
        .soundSnoring3         = SOUND_LUIGI_SNORING3,
        .soundSoLongaBowser    = SOUND_LUIGI_SO_LONGA_BOWSER,
        .soundImaTired         = SOUND_LUIGI_IMA_TIRED,
        .soundLetsAGo          = SOUND_LUIGI_LETS_A_GO,
        .soundOkeyDokey        = SOUND_LUIGI_OKEY_DOKEY,
    },

    [CT_WARIO] = {
        .type                  = CT_WARIO,
        .name                  = "Wario",
        .hudHead               = '[',
        .hudHeadTexture        = { .texture = (u8*)texture_hud_char_wario_head, .bitSize = 8, .width = 16, .height = 16, .name = "texture_hud_char_wario_head" },
        .cameraHudHead         = GLYPH_CAM_WARIO_HEAD,
        .modelId               = MODEL_WARIO,
        .capModelId            = MODEL_WARIOS_CAP,
        .capMetalModelId       = MODEL_WARIOS_METAL_CAP,
        .capWingModelId        = MODEL_WARIOS_WING_CAP,
        .capMetalWingModelId   = MODEL_WARIOS_WINGED_METAL_CAP,
        .capEnemyLayer         = LAYER_OPAQUE,
        .capEnemyGfx           = wario_cap_seg3_dl_03022F48,
        .capEnemyDecalGfx      = NULL,
        .torsoRotMult          = 1.0f,
        // anim
        .animOffsetEnabled     = false,

        // character anims
        BASE_ANIMS(),

        // sounds
        .soundFreqScale        = 1.0f,
        .soundYahWahHoo        = SOUND_WARIO_YAH_WAH_HOO,
        .soundHoohoo           = SOUND_WARIO_HOOHOO,
        .soundYahoo            = SOUND_WARIO_YAHOO,
        .soundUh               = SOUND_WARIO_UH,
        .soundHrmm             = SOUND_WARIO_HRMM,
        .soundWah2             = SOUND_WARIO_WAH2,
        .soundWhoa             = SOUND_WARIO_WHOA,
        .soundEeuh             = SOUND_WARIO_EEUH,
        .soundAttacked         = SOUND_WARIO_ATTACKED,
        .soundOoof             = SOUND_WARIO_OOOF,
        .soundOoof2            = SOUND_WARIO_OOOF2,
        .soundHereWeGo         = SOUND_WARIO_HERE_WE_GO,
        .soundYawning          = SOUND_WARIO_YAWNING,
        .soundSnoring1         = SOUND_WARIO_SNORING1,
        .soundSnoring2         = SOUND_WARIO_SNORING2,
        .soundWaaaooow         = SOUND_WARIO_WAAAOOOW,
        .soundHaha             = SOUND_WARIO_HAHA,
        .soundHaha_2           = SOUND_WARIO_HAHA_2,
        .soundUh2              = SOUND_WARIO_UH2,
        .soundUh2_2            = SOUND_WARIO_UH2_2,
        .soundOnFire           = SOUND_WARIO_ON_FIRE,
        .soundDying            = SOUND_WARIO_DYING,
        .soundPantingCold      = SOUND_WARIO_PANTING_COLD,
        .soundPanting          = SOUND_WARIO_PANTING,
        .soundCoughing1        = SOUND_WARIO_COUGHING1,
        .soundCoughing2        = SOUND_WARIO_COUGHING2,
        .soundCoughing3        = SOUND_WARIO_COUGHING3,
        .soundPunchYah         = SOUND_WARIO_PUNCH_YAH,
        .soundPunchHoo         = SOUND_WARIO_PUNCH_HOO,
        .soundMamaMia          = SOUND_WARIO_MAMA_MIA,
        .soundGroundPoundWah   = SOUND_WARIO_GROUND_POUND_WAH,
        .soundDrowning         = SOUND_WARIO_DROWNING,
        .soundPunchWah         = SOUND_WARIO_PUNCH_WAH,
        .soundYahooWahaYippee  = SOUND_WARIO_YAHOO_WAHA_YIPPEE,
        .soundDoh              = SOUND_WARIO_DOH,
        .soundGameOver         = SOUND_WARIO_GAME_OVER,
        .soundHello            = SOUND_WARIO_HELLO,
        .soundPressStartToPlay = SOUND_WARIO_PRESS_START_TO_PLAY,
        .soundTwirlBounce      = SOUND_WARIO_TWIRL_BOUNCE,
        .soundSnoring3         = SOUND_WARIO_SNORING3,
        .soundSoLongaBowser    = SOUND_WARIO_SO_LONGA_BOWSER,
        .soundImaTired         = SOUND_WARIO_IMA_TIRED,
        .soundLetsAGo          = SOUND_WARIO_LETS_A_GO,
        .soundOkeyDokey        = SOUND_WARIO_OKEY_DOKEY,
    },
};

enum AnimType {
    ANIM_TYPE_NONE,
    ANIM_TYPE_LOWY,
    ANIM_TYPE_FEET,
    ANIM_TYPE_HAND,
};

#define ANIM_TYPE_MAX 211
u8 sAnimTypes[ANIM_TYPE_MAX] = {
    ANIM_TYPE_HAND, ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_FEET,
    ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_FEET, ANIM_TYPE_FEET, ANIM_TYPE_FEET,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_FEET, ANIM_TYPE_FEET, ANIM_TYPE_FEET, ANIM_TYPE_NONE, ANIM_TYPE_LOWY,
    ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_HAND, ANIM_TYPE_LOWY,
    ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_HAND, ANIM_TYPE_FEET, ANIM_TYPE_HAND, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_FEET, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_FEET, ANIM_TYPE_NONE, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_FEET,
    ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_FEET, ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_HAND, ANIM_TYPE_HAND, ANIM_TYPE_LOWY,
    ANIM_TYPE_FEET, ANIM_TYPE_FEET, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_FEET,
    ANIM_TYPE_FEET, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_NONE,
    ANIM_TYPE_NONE, ANIM_TYPE_FEET, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_FEET, ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_NONE,
    ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_HAND, ANIM_TYPE_HAND,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_FEET, ANIM_TYPE_LOWY, ANIM_TYPE_LOWY,
    ANIM_TYPE_LOWY, ANIM_TYPE_LOWY, ANIM_TYPE_NONE, ANIM_TYPE_NONE, ANIM_TYPE_FEET,
    ANIM_TYPE_FEET,
};

struct Character* get_character(struct MarioState* m) {
    return (m == NULL || m->character == NULL)
        ? &gCharacters[CT_MARIO]
        : m->character;
}

static s32 get_character_sound(struct MarioState* m, enum CharacterSound characterSound) {
    if (m == NULL || m->marioObj == NULL) { return 0; }

    s32 override = 0;
    if (smlua_call_event_hooks_mario_character_sound_param_ret_int(HOOK_CHARACTER_SOUND, m, characterSound, &override)) {
        return override;
    }

    struct Character* character = ((m == NULL || m->character == NULL) ? &gCharacters[CT_MARIO] : m->character);

    if (characterSound < 0 || characterSound >= CHAR_SOUND_MAX) { return 0; }
    return character->sounds[characterSound];
}

static void play_character_sound_internal(struct MarioState *m, enum CharacterSound characterSound, u32 offset, u32 flags) {
    if (m != NULL && (m->flags & flags) == 0) {
        s32 sound = get_character_sound(m, characterSound);
        if (sound != 0) {
            struct Character* character = get_character(m);
            f32 *pos = (m->marioObj != NULL ? m->marioObj->header.gfx.cameraToObject : gGlobalSoundSource);
            play_sound_with_freq_scale(sound + offset, pos, character->soundFreqScale);
        }
        m->flags |= flags;
    }
}

void play_character_sound(struct MarioState* m, enum CharacterSound characterSound) {
    play_character_sound_internal(m, characterSound, 0, 0);
}

void play_character_sound_offset(struct MarioState* m, enum CharacterSound characterSound, u32 offset) {
    play_character_sound_internal(m, characterSound, offset, 0);
}

void play_character_sound_if_no_flag(struct MarioState* m, enum CharacterSound characterSound, u32 flags) {
    play_character_sound_internal(m, characterSound, 0, flags);
}

f32 get_character_anim_offset(struct MarioState* m) {
    if (m == NULL || m->marioObj == NULL) { return 0; }
    struct Object* marioObj = m->marioObj;
    if (!marioObj) { return 0; }
    struct Character* c = get_character(m);
    if (!c || !c->animOffsetEnabled) { return 0; }
    s32 animID = marioObj->header.gfx.animInfo.animID;
    if (animID < 0 || animID >= ANIM_TYPE_MAX) { return 0; }

    switch (sAnimTypes[animID]) {
        case ANIM_TYPE_LOWY:
            if (m->minimumBoneY < c->animOffsetLowYPoint) {
                return c->animOffsetLowYPoint - m->minimumBoneY;
            }
            break;
        case ANIM_TYPE_FEET:
            return c->animOffsetFeet;
            break;
        case ANIM_TYPE_HAND:
            return c->animOffsetHand;
            break;
    }
    return 0;
}

void update_character_anim_offset(struct MarioState* m) {
    if (m == NULL || m->marioObj == NULL) { return; }
    struct Object* marioObj = m->marioObj;
    if (!marioObj) { return; }
    struct Character* c = get_character(m);
    if (!c || !c->animOffsetEnabled) { return; }

    f32 targetOffset = get_character_anim_offset(m);

    // smooth
    f32 alpha = (fabs(targetOffset - m->curAnimOffset) / 80.0f) + 0.5f;
    alpha = (alpha + 0.5f) / 2.0f;
    alpha *= alpha;
    m->curAnimOffset = (m->curAnimOffset * alpha) + (targetOffset * (1.0f - alpha));
    if (m->curAnimOffset > 40)  { m->curAnimOffset = 40; }
    if (m->curAnimOffset < -40) { m->curAnimOffset = -40; }

    marioObj->header.gfx.pos[1] = m->pos[1] + m->curAnimOffset;
    marioObj->header.gfx.node.flags |= GRAPH_RENDER_PLAYER;
}

s32 get_character_anim(struct MarioState* m, enum CharacterAnimID characterAnim) {
    if (m == NULL || m->marioObj == NULL) { return 0; }

    struct Character* character = ((m == NULL || m->character == NULL) ? &gCharacters[CT_MARIO] : m->character);
    if (!character || characterAnim < 0 || characterAnim >= CHAR_ANIM_MAX) { return characterAnim; }
    return character->anims[characterAnim];
}
