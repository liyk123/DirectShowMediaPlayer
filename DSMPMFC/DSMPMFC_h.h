

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0613 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for DSMPMFC.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0613 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __DSMPMFC_h_h__
#define __DSMPMFC_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDSMPMFC_FWD_DEFINED__
#define __IDSMPMFC_FWD_DEFINED__
typedef interface IDSMPMFC IDSMPMFC;

#endif 	/* __IDSMPMFC_FWD_DEFINED__ */


#ifndef __CDSMPMFCDoc_FWD_DEFINED__
#define __CDSMPMFCDoc_FWD_DEFINED__

#ifdef __cplusplus
typedef class CDSMPMFCDoc CDSMPMFCDoc;
#else
typedef struct CDSMPMFCDoc CDSMPMFCDoc;
#endif /* __cplusplus */

#endif 	/* __CDSMPMFCDoc_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __DSMPMFC_LIBRARY_DEFINED__
#define __DSMPMFC_LIBRARY_DEFINED__

/* library DSMPMFC */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_DSMPMFC;

#ifndef __IDSMPMFC_DISPINTERFACE_DEFINED__
#define __IDSMPMFC_DISPINTERFACE_DEFINED__

/* dispinterface IDSMPMFC */
/* [uuid] */ 


EXTERN_C const IID DIID_IDSMPMFC;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("25FA09EB-6767-47CC-85C0-F20C3A12DE67")
    IDSMPMFC : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IDSMPMFCVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDSMPMFC * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDSMPMFC * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDSMPMFC * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDSMPMFC * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDSMPMFC * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDSMPMFC * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDSMPMFC * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IDSMPMFCVtbl;

    interface IDSMPMFC
    {
        CONST_VTBL struct IDSMPMFCVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDSMPMFC_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDSMPMFC_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDSMPMFC_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDSMPMFC_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDSMPMFC_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDSMPMFC_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDSMPMFC_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IDSMPMFC_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CDSMPMFCDoc;

#ifdef __cplusplus

class DECLSPEC_UUID("B3BC2505-D74E-4744-A45B-A0EEE31AE01B")
CDSMPMFCDoc;
#endif
#endif /* __DSMPMFC_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


