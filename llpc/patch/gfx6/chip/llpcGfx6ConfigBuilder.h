/*
 ***********************************************************************************************************************
 *
 *  Copyright (c) 2017-2020 Advanced Micro Devices, Inc. All Rights Reserved.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *
 **********************************************************************************************************************/
/**
 ***********************************************************************************************************************
 * @file  llpcGfx6ConfigBuilder.h
 * @brief LLPC header file: contains declaration of class Llpc::Gfx6::ConfigBuilder.
 ***********************************************************************************************************************
 */
#pragma once

#include "llpcConfigBuilderBase.h"
#include "llpcGfx6Chip.h"

namespace Llpc
{

struct ElfDataEntry;
struct ResourceUsage;

namespace Gfx6
{

// =====================================================================================================================
// Represents the builder to generate register configurations for GFX6-generation chips.
class ConfigBuilder : public ConfigBuilderBase
{
public:
    ConfigBuilder(llvm::Module* pModule, PipelineState* pPipelineState)
        : ConfigBuilderBase(pModule, pPipelineState) {}

    void BuildPalMetadata();

    void BuildPipelineVsFsRegConfig();
    void BuildPipelineVsTsFsRegConfig();
    void BuildPipelineVsGsFsRegConfig();
    void BuildPipelineVsTsGsFsRegConfig();
    void BuildPipelineCsRegConfig();

private:
    ConfigBuilder() = delete;
    ConfigBuilder(const ConfigBuilder&) = delete;
    ConfigBuilder& operator=(const ConfigBuilder&) = delete;

    template <typename T>
    void BuildVsRegConfig(ShaderStage         shaderStage,
                          T*                  pConfig);

    template <typename T>
    void BuildHsRegConfig(ShaderStage         shaderStage,
                          T*                  pConfig);

    template <typename T>
    void BuildEsRegConfig(ShaderStage         shaderStage,
                          T*                  pConfig);

    template <typename T>
    void BuildLsRegConfig(ShaderStage         shaderStage,
                          T*                  pConfig);

    template <typename T>
    void BuildGsRegConfig(ShaderStage         shaderStage,
                          T*                  pConfig);

    template <typename T>
    void BuildPsRegConfig(ShaderStage         shaderStage,
                          T*                  pConfig);

    void BuildCsRegConfig(ShaderStage  shaderStage,
                          CsRegConfig* pConfig);

    void BuildUserDataConfig(ShaderStage shaderStage,
                             uint32_t    startUserData);

    template <typename T>
    void SetupVgtTfParam(T* pConfig);

};

} // Gfx6

} // Llpc
