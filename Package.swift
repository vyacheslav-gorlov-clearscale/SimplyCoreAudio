// swift-tools-version:5.5
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "SimplyCoreAudio",
    platforms: [
        .macOS(.v12),
        .macCatalyst(.v15)
    ],
    
    products: [
        .library(name: "SimplyCoreAudio",
                 type: .static,
                 targets: ["SimplyCoreAudio"])
    ],
    
    dependencies: [
        .package(url: "https://github.com/apple/swift-atomics.git", from: "1.0.2")
    ],
    
    targets: [
        .target(
            name: "SimplyCoreAudio",
            dependencies: [
                .target(name: "SimplyCoreAudioC"),
                .product(name: "Atomics", package: "swift-atomics")
            ]
        ),
        .target(name: "SimplyCoreAudioC",
                publicHeadersPath: "."
        ),
        .testTarget(
            name: "SimplyCoreAudioTests",
            dependencies: ["SimplyCoreAudio"]
        ),

    ],
    swiftLanguageVersions: [.v5]
)
