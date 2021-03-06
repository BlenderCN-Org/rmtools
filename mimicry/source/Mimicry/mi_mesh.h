#ifndef MI_MESH_H_INCLUDED
#define MI_MESH_H_INCLUDED

class mCMesh
{
public:
    struct SUniVert
    {
        mCVec3 const *  m_pVert;
        mCColor const * m_pVColor;
        mCVec3 const *  m_pTVert;
        mCVec3 const *  m_pVNormal;
        mCVec3 const *  m_pVTangent;
        MIFloat         m_fVTHandiness;
        MIUInt          m_uMatID;
        MIUInt          m_uBaseVertIndex;
    };
public:
    mCMesh( mCMesh const & a_meshSource );
    mCMesh( void );
   ~mCMesh( void );
public:
    mCMesh & operator = ( mCMesh const & a_meshSource );
public:
    mCMaxFace *       AccessFaces( void );
    mCVec3 *          AccessTVerts( void );
    mCFace *          AccessTVFaces( void );
    mCColor *         AccessVertexColors( void );
    mCVec3 *          AccessVerts( void );
    mCFace *          AccessVNFaces( void );
    mCVec3 *          AccessVNormals( void );
    mCVec3 *          AccessVTangents( void );
    MIFloat *         AccessVTHandiness( void );
    mCFace *          AccessVTFaces( void );
    mCBox             CalcExtents( void ) const;
    void              CalcFakeTexturing( void );
    mEResult          CalcFTangents( mTArray< mCVec3 > & a_arrDest, mTArray< MIFloat > & a_arrHandiness );
    void              CalcUniVertMesh( mTArray< SUniVert > & a_arrUniVertsDest, mTArray< mCFace > & a_arrUVFacesDest, MIBool a_bIgnoreVTangents = MIFalse ) const;
    void              CalcVNormalsBySGs( void );
    void              CalcVNormalsByAngle( MIFloat a_fMaxAngleDeg );
    mEResult          CalcVTangents( void );
    void              Clear( void );
    void              CopyTVFacesFromFaces( void );
    void              CopyVNFacesFromFaces( void );
    void              CopyVTFacesFromFaces( void );
    void              ExtractByID( MIUInt a_uMatID, mCMesh & a_meshDest ) const;
    mCMaxFace const * GetFaces( void ) const;
    MIUInt            GetNumFaces( void ) const;
    MIUInt            GetNumTVerts( void ) const;
    MIUInt            GetNumVerts( void ) const;
    MIUInt            GetNumVNormals( void ) const;
    MIUInt            GetNumVTangents( void ) const;
    mCVec3 const *    GetTVerts( void ) const;
    mCFace const *    GetTVFaces( void ) const;
    mCColor const *   GetVertexColors( void ) const;
    mCVec3 const *    GetVerts( void ) const;
    mCFace const *    GetVNFaces( void ) const;
    mCVec3 const *    GetVNormals( void ) const;
    mCVec3 const *    GetVTangents( void ) const;
    MIFloat const *   GetVTHandiness( void ) const;
    mCFace const *    GetVTFaces( void ) const;
    MIBool            HasTVFaces( void ) const;
    MIBool            HasVertexColors( void ) const;
    MIBool            HasVNFaces( void ) const;
    MIBool            HasVTFaces( void ) const;
    void              Merge( mCMesh a_meshOther, mCMaterialBase const * a_pMaterial = 0, mCMaterialBase const * a_pOtherMaterial = 0, mCMultiMaterial * a_pComposedMaterialDest = 0 );
    void              SetHasVertexColors( MIBool a_bHasVertexColors );
    void              SetNumFaces( MIUInt a_uCount );
    void              SetNumTVerts( MIUInt a_uCount );
    void              SetNumVerts( MIUInt a_uCount );
    void              SetNumVNormals( MIUInt a_uCount );
    void              SetNumVTangents( MIUInt a_uCount );
    void              SortFacesByMatID( void );
    void              Swap( mCMesh & a_meshOther );
    void              WeldVertices( void );
private:
    void CalcIndicesPerVert( mTArray< MIUInt > & a_arrFirstIndexPerVert, mTArray< MIUInt > & a_arrNextIndexPerIndex ) const;
    void CalcVNormals( MIBool a_bUseAnglesNotSGs, MIFloat a_fMinCosine = 0.0f );
private:
    mTArray< mCVec3 >    m_arrVertices;
    mTArray< mCVec3 >    m_arrTextureVertices;
    mTArray< mCVec3 >    m_arrVertexNormals;
    mTArray< mCVec3 >    m_arrVertexTangents;
    mTArray< MIFloat >   m_arrVTHandiness;
    mTArray< mCMaxFace > m_arrFaces;
    mTArray< mCFace >    m_arrTextureVertexFaces;
    mTArray< mCFace >    m_arrVertexNormalFaces;
    mTArray< mCFace >    m_arrVertexTangentFaces;
    mTArray< mCColor >   m_arrVertexColors;
};

#endif
