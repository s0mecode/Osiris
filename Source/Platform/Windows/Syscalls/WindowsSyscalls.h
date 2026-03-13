#pragma once

#include <windows.h>
#include <winternl.h>

#include "SyscallParams.h"
#include "WindowsSyscallIndex.h"

#if !defined(__MINGW32__) && !defined(__MINGW64__)
extern "C" std::size_t systemCall(const SyscallParams* params, ...);
#endif

struct IO_APC_ROUTINE;

#if defined(__MINGW32__) || defined(__MINGW64__)
extern "C" {
NTSYSCALLAPI NTSTATUS NTAPI NtCreateFile(
    PHANDLE fileHandle,
    ACCESS_MASK desiredAccess,
    POBJECT_ATTRIBUTES objectAttributes,
    PIO_STATUS_BLOCK ioStatusBlock,
    PLARGE_INTEGER allocationSize,
    ULONG fileAttributes,
    ULONG shareAccess,
    ULONG createDisposition,
    ULONG createOptions,
    PVOID eaBuffer,
    ULONG eaLength);
NTSYSCALLAPI NTSTATUS NTAPI NtReadFile(
    HANDLE fileHandle,
    HANDLE event,
    IO_APC_ROUTINE* apcRoutine,
    PVOID apcContext,
    PIO_STATUS_BLOCK ioStatusBlock,
    PVOID buffer,
    ULONG length,
    PLARGE_INTEGER byteOffset,
    PULONG key);
NTSYSCALLAPI NTSTATUS NTAPI NtWriteFile(
    HANDLE fileHandle,
    HANDLE event,
    IO_APC_ROUTINE* apcRoutine,
    PVOID apcContext,
    PIO_STATUS_BLOCK ioStatusBlock,
    PVOID buffer,
    ULONG length,
    PLARGE_INTEGER byteOffset,
    PULONG key);
NTSYSCALLAPI NTSTATUS NTAPI NtSetInformationFile(
    HANDLE fileHandle,
    PIO_STATUS_BLOCK ioStatusBlock,
    PVOID fileInformation,
    ULONG length,
    FILE_INFORMATION_CLASS fileInformationClass);
NTSYSCALLAPI NTSTATUS NTAPI NtClose(HANDLE handle);
}
#endif

struct WindowsSyscalls {
    static NTSTATUS NtCreateFile(
        HANDLE* fileHandle,
        ACCESS_MASK desiredAccess,
        OBJECT_ATTRIBUTES* objectAttributes,
        IO_STATUS_BLOCK* ioStatusBlock,
        LARGE_INTEGER* allocationSize,
        ULONG fileAttributes,
        ULONG shareAccess,
        ULONG createDisposition,
        ULONG createOptions,
        void* eaBuffer,
        ULONG eaLength) noexcept
    {
#if defined(__MINGW32__) || defined(__MINGW64__)
        return ::NtCreateFile(fileHandle, desiredAccess, objectAttributes, ioStatusBlock, allocationSize, fileAttributes, shareAccess, createDisposition, createOptions, eaBuffer, eaLength);
#else
        const SyscallParams params{WindowsSyscallIndex::NtCreateFile, reinterpret_cast<std::uintptr_t>(fileHandle)};
        return static_cast<NTSTATUS>(systemCall(&params, desiredAccess, objectAttributes, ioStatusBlock, allocationSize, fileAttributes, shareAccess, createDisposition, createOptions, eaBuffer, eaLength));
#endif
    }

    static NTSTATUS NtReadFile(HANDLE fileHandle, HANDLE event, IO_APC_ROUTINE* apcRoutine, void* apcContext, IO_STATUS_BLOCK* ioStatusBlock, void* buffer, ULONG length, LARGE_INTEGER* byteOffset, ULONG* key) noexcept
    {
#if defined(__MINGW32__) || defined(__MINGW64__)
        return ::NtReadFile(fileHandle, event, apcRoutine, apcContext, ioStatusBlock, buffer, length, byteOffset, key);
#else
        const SyscallParams params{WindowsSyscallIndex::NtReadFile, reinterpret_cast<std::uintptr_t>(fileHandle)};
        return static_cast<NTSTATUS>(systemCall(&params, event, apcRoutine, apcContext, ioStatusBlock, buffer, length, byteOffset, key));
#endif
    }

    static NTSTATUS NtWriteFile(HANDLE fileHandle, HANDLE event, IO_APC_ROUTINE* apcRoutine, void* apcContext, IO_STATUS_BLOCK* ioStatusBlock, void* buffer, ULONG length, LARGE_INTEGER* byteOffset, ULONG* key) noexcept
    {
#if defined(__MINGW32__) || defined(__MINGW64__)
        return ::NtWriteFile(fileHandle, event, apcRoutine, apcContext, ioStatusBlock, buffer, length, byteOffset, key);
#else
        const SyscallParams params{WindowsSyscallIndex::NtWriteFile, reinterpret_cast<std::uintptr_t>(fileHandle)};
        return static_cast<NTSTATUS>(systemCall(&params, event, apcRoutine, apcContext, ioStatusBlock, buffer, length, byteOffset, key));
#endif
    }

    static NTSTATUS NtSetInformationFile(HANDLE fileHandle, IO_STATUS_BLOCK* ioStatusBlock, void* fileInformation, ULONG length, FILE_INFORMATION_CLASS fileInformationClass) noexcept
    {
#if defined(__MINGW32__) || defined(__MINGW64__)
        return ::NtSetInformationFile(fileHandle, ioStatusBlock, fileInformation, length, fileInformationClass);
#else
        const SyscallParams params{WindowsSyscallIndex::NtSetInformationFile, reinterpret_cast<std::uintptr_t>(fileHandle)};
        return static_cast<NTSTATUS>(systemCall(&params, ioStatusBlock, fileInformation, length, fileInformationClass));
#endif
    }

    static NTSTATUS NtClose(HANDLE handle) noexcept
    {
#if defined(__MINGW32__) || defined(__MINGW64__)
        return ::NtClose(handle);
#else
        const SyscallParams params{WindowsSyscallIndex::NtClose, reinterpret_cast<std::uintptr_t>(handle)};
        return static_cast<NTSTATUS>(systemCall(&params));
#endif
    }
};
