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
#include <algorithm>

using namespace std;

SUModelRef _model = SU_INVALID;
SUEntitiesRef _entities = SU_INVALID;
vector<SUFaceRef> _faces;
vector<SUVertexRef> _vertices;
vector<SUEdgeRef> _edges;



bool operator<(const SUVertexRef &a, const SUVertexRef &b)
{
    return a.ptr < b.ptr;
}

bool operator==(const SUVertexRef &a, const SUVertexRef &b)
{
    return a.ptr == b.ptr;
}

void printVertices()
{
	size_t i;
	for (i = 0; i < _vertices.size(); i++)
	{
        std::sort(_vertices.begin(), _vertices.end());
        _vertices.erase(unique(_vertices.begin(), _vertices.end()), _vertices.end());

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

    size_t edgeCount = 0;
    result = SUEntitiesGetNumEdges(_entities, false, &edgeCount);

    _edges = vector<SUEdgeRef>(edgeCount);
    result = SUEntitiesGetEdges(_entities, false, edgeCount, &_edges[0], &edgeCount);

    for (i = 0; i < edgeCount; i++){
        
        SUVertexRef startVertex = SU_INVALID;
        result = SUEdgeGetStartVertex(_edges[i], &startVertex);
        _vertices.push_back(startVertex);

        SUVertexRef endVertex = SU_INVALID;
        result = SUEdgeGetEndVertex(_edges[i], &endVertex);
        _vertices.push_back(endVertex);

    }

	printVertices();

	return 0;
}




