// Copyright 2014 Trimble Navigation Ltd. All Rights Reserved.

#ifndef SLAPI_MODEL_GUIDE_POINT_H_
#define SLAPI_MODEL_GUIDE_POINT_H_

#include <slapi/slapi.h>
#include <slapi/geometry.h>
#include <slapi/model/defs.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
@struct SUGuidePointRef
@brief  A guide point that has a position.
@since SketchUp 2014 M1, API 2.1
*/

/**
@brief Converts from an \ref SUGuidePointRef to an \ref SUEntityRef. This is
       essentially an upcast operation.
@since SketchUp 2014 M1, API 2.1
@param[in] guide_point The guide point object.
@return
- The converted \ref SUEntityRef if guide_point is a valid object
- If not, the returned reference will be invalid
*/
SU_EXPORT SUEntityRef SUGuidePointToEntity(SUGuidePointRef guide_point);

/**
@brief Converts from an \ref SUEntityRef to an \ref SUGuidePointRef.
       This is essentially a downcast operation so the given \ref SUEntityRef
       must be convertible to an \ref SUGuidePointRef.
@since SketchUp 2014 M1, API 2.1
@param[in] entity The entity object.
@return
- The converted \ref SUGuidePointRef if the downcast operation succeeds
- If the downcast operation fails, the returned reference will be invalid
*/
SU_EXPORT SUGuidePointRef SUGuidePointFromEntity(SUEntityRef entity);

/**
@brief Creates a guide point object. The guide point object must be subsequently
       deallocated with \ref SUGuidePointRelease unless it is associated with a
       parent object.
@since SketchUp 2014 M1, API 2.1
@param[in]  guide_point The guide point object.
@param[out] position    The guide point position.
@return
- \ref SU_ERROR_NONE on success
- \ref c if guide_point is NULL
- \ref SU_ERROR_OVERWRITE_VALID if guide_point references a valid object
- \ref SU_ERROR_NULL_POINTER_INPUT if position is NULL
*/
SU_RESULT SUGuidePointCreate(SUGuidePointRef* guide_point,
                             const struct SUPoint3D* position);

/**
@brief Releases a guide point object. The guide point object must have been
       created with \ref SUGuidePointCreate and not subsequently associated with
       a parent object (e.g. \ref SUEntitiesAddGuidePoints).
@since SketchUp 2014 M1, API 2.1
@param[in] guide_point The guide point object.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_NULL_POINTER_INPUT if guide_point is NULL
- \ref SU_ERROR_INVALID_INPUT if guide_point does not reference a valid object
*/
SU_RESULT SUGuidePointRelease(SUGuidePointRef* guide_point);

/**
@brief Retrieves the position of a guide point object.
@since SketchUp 2014 M1, API 2.1
@param[in]  guide_point The guide point object.
@param[out] position           The guide point position.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if guide point is an invalid object
- \ref SU_ERROR_NULL_POINTER_OUTPUT if position is NULL
*/
SU_RESULT SUGuidePointGetPosition(SUGuidePointRef guide_point,
                                  struct SUPoint3D* position);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // SLAPI_MODEL_GUIDE_POINT_H_
