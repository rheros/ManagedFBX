#pragma once

#include "Polygon.h"

using namespace System::Collections::Generic;

namespace ManagedFbx
{
	public ref class Mesh
	{
	public:
		property_r(array<Polygon>^, Polygons);
		property_rw(array<Vector3>^, Vertices);
		property_rw(array<Vector3>^, Normals);
		property_r(array<Vector2>^, TextureCoords);
		property_r(array<Colour>^, VertexColours);
		property_r(array<int>^, MaterialIDs);
		property_r(bool, Triangulated);
		property_r(bool, Valid);
		property_r(int, NormalMappingMode);
		property_r(FbxMesh*, NativePtr);
		property int UVLayer;

		Mesh ^Triangulate();

		int GetUVIndex(int polygon, int index);
		int GetMaterialId(int polygon);
		void Test();
		Vector3 GetVertexNormal(int polygon, int index);
		void AddPolygons(List<int>^ polygonIndex);
		void AddPolygon(List<int>^ polygonIndex);


	internal:
		Mesh(FbxMesh *nativeMesh);

	private:
		FbxMesh *m_nativeMesh;
	};
}