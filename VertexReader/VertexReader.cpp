// VertexReader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <slapi/slapi.h>
#include <slapi/geometry.h>
#include <slapi/initialize.h>
#include <slapi/unicodestring.h>
#include <slapi/model/model.h>
#include <slapi/model/entities.h>
#include <slapi/model/face.h>
#include <slapi/model/edge.h>
#include <slapi/model/vertex.h>
#include <vector>

using namespace std;

SUModelRef _model = SU_INVALID;
SUEntitiesRef _entities = SU_INVALID;
vector<SUFaceRef> _faces;
vector<SUVertexRef> _vertices;

void printVertices()
{
	size_t i;
	for (i = 0; i < _vertices.size(); i++)
	{
		SUPoint3D point;
		SUResult result = SUVertexGetPosition(_vertices[i], &point);

		printf("{ %5.1ff, %5.1ff, %5.1ff }\n", point.x, point.y, point.z);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	size_t i, j;
	SUResult result;

	SUInitialize();

	result = SUModelCreateFromFile(&_model, "sample.skp");
	result = SUModelGetEntities(_model, &_entities);

	size_t faceCount = 0;
	result = SUEntitiesGetNumFaces(_entities, &faceCount);
	
	_faces = vector<SUFaceRef>(faceCount);
	result = SUEntitiesGetFaces(_entities, faceCount, &_faces[0], &faceCount);

	for (i = 0; i < faceCount; i++){
		size_t vertexCount;
		result = SUFaceGetNumVertices(_faces[i], &vertexCount);

		_vertices.resize(_vertices.size() + vertexCount);
		result = SUFaceGetVertices(_faces[i], vertexCount, &_vertices[_vertices.size() - vertexCount], &vertexCount);
	}

	printVertices();

	return 0;
}




