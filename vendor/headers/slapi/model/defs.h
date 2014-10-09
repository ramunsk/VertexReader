// Copyright 2013 Trimble Navigation Ltd. All Rights Reserved.

#ifndef SLAPI_MODEL_DEFS_H_
#define SLAPI_MODEL_DEFS_H_

#include <slapi/slapi.h>

#pragma pack(push, 8)

DEFINE_SU_TYPE(SUAttributeDictionaryRef)
DEFINE_SU_TYPE(SUCameraRef)
DEFINE_SU_TYPE(SUComponentDefinitionRef)
DEFINE_SU_TYPE(SUComponentInstanceRef)
DEFINE_SU_TYPE(SUCurveRef)
DEFINE_SU_TYPE(SUDrawingElementRef)
DEFINE_SU_TYPE(SUEdgeRef)
DEFINE_SU_TYPE(SUEdgeUseRef)
DEFINE_SU_TYPE(SUEntitiesRef)
DEFINE_SU_TYPE(SUEntityRef)
DEFINE_SU_TYPE(SUFaceRef)
DEFINE_SU_TYPE(SUGroupRef)
DEFINE_SU_TYPE(SUGuidePointRef)
DEFINE_SU_TYPE(SUImageRef)
DEFINE_SU_TYPE(SULayerRef)
DEFINE_SU_TYPE(SULocationRef)
DEFINE_SU_TYPE(SULoopRef)
DEFINE_SU_TYPE(SUGeometryInputRef)
DEFINE_SU_TYPE(SUMeshHelperRef)
DEFINE_SU_TYPE(SUMaterialRef)
DEFINE_SU_TYPE(SUModelRef)
DEFINE_SU_TYPE(SUOpeningRef)
DEFINE_SU_TYPE(SUOptionsManagerRef)
DEFINE_SU_TYPE(SUOptionsProviderRef)
DEFINE_SU_TYPE(SUPolyline3dRef)
DEFINE_SU_TYPE(SUSceneRef)
DEFINE_SU_TYPE(SUTextureRef)
DEFINE_SU_TYPE(SUTextureWriterRef)
DEFINE_SU_TYPE(SUTypedValueRef);
DEFINE_SU_TYPE(SUUVHelperRef)
DEFINE_SU_TYPE(SUVertexRef)
DEFINE_SU_TYPE(SURenderingOptionsRef)

/**
@enum SURefType
@brief Types of concrete object references.
*/
enum SURefType {
    SURefType_Unknown = 0,
    SURefType_AttributeDictionary,
    SURefType_Camera,
    SURefType_ComponentDefinition,
    SURefType_ComponentInstance,
    SURefType_Curve,
    SURefType_Edge,
    SURefType_EdgeUse,
    SURefType_Entities,
    SURefType_Face,
    SURefType_Group,
    SURefType_Image,
    SURefType_Layer,
    SURefType_Location,
    SURefType_Loop,
    SURefType_MeshHelper,
    SURefType_Material,
    SURefType_Model,
    SURefType_Polyline3D,
    SURefType_Scene,
    SURefType_Texture,
    SURefType_TextureWriter,
    SURefType_TypedValue,
    SURefType_UVHelper,
    SURefType_Vertex,
    SURefType_RenderingOptions,
    SURefType_GuidePoint
};

#pragma pack(pop)

#endif  // SLAPI_MODEL_DEFS_H_
